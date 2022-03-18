(function () {

  function initFilePreview(containerEl) {
    const sitePrefix = containerEl.dataset.filePathPrefix;
    function setPath(path) {
      containerEl.innerHTML = '';
      const previewEl = containerEl.appendChild(document.createElement('div'));
      const linkEl = previewEl.appendChild(document.createElement('a'));

      linkEl.setAttribute('href', `${sitePrefix}${path}`)
      const pathParts = path.split('/');
      const filename = pathParts[pathParts.length - 1];
      linkEl.setAttribute('download', filename);
      linkEl.innerHTML = `Download<br />${filename}`;
    }
    return {
      setPath,
    }
  }

  function initFileBrowser() {
    const rootContainer = document.querySelector('[data-file-browser]');

    // File listing and preview

    const fileListContainer = document.querySelector('[data-file-list]');
    const previewContainer = document.querySelector('[data-file-preview]');

    if (!fileListContainer || !previewContainer) {
      throw new Error("Unable to obtain file list or preview container");
    }

    const itemPaths = window[fileListContainer.dataset.fileList];

    if (!itemPaths) {
      throw new Error("Unable to obtain item paths");
    }

    const itemsAsObject = itemPaths.
      map(path => ({ [path]: true })).
      reduce((prev, curr) => ({ ...prev, ...curr }), {});

    const itemsAsHierarchicalObject = unflattenObject(itemsAsObject);

    const topLevelItems = Object.keys(itemsAsHierarchicalObject);

    let initialItems, initialSelectedItem;
    try {
      initialItems = JSON.parse(window.localStorage.getItem('initial-items'));
      const missingItem = initialItems.find(ii => itemPaths.find(ip => ip === ii || ip.startsWith(`${ii}/`)) < 0);
      if (missingItem) {
        throw new Error(`Invalid initial items stored (${missingItem})`);
      }
      initialSelectedItem = window.localStorage.getItem('selected-item');
    } catch (e) {
      initialItems = topLevelItems;
      initialSelectedItem = null;
      window.localStorage.removeItem('initial-items');
      window.localStorage.removeItem('selected-item');
      console.error("Error loading stored data", e);
    }

    const listing = window.createWindowedListing(
      initialItems,
      fileListContainer,
      initialSelectedItem,
      onSelectItem,
      getItemLabel,
      getItemChildren,
      isExpandable,
    );

    const filePreview = initFilePreview(previewContainer);

    async function onSelectItem(itemPath, item) {
      listing.getVisibleElements().map(element => element.classList.remove('selected'));
      item.classList.add('selected');
      window.localStorage.setItem('selected-item', itemPath);

      // If shown items are a result of search, do not update stored state
      if (!itemIDsPreSearch) {
        window.localStorage.setItem('initial-items', JSON.stringify(listing.getItemIDs()));
      }

      if (await isExpandable(itemPath)) {
      } else {
        filePreview.setPath(itemPath);
      }
    }

    async function getItemLabel(itemID) {
      const el = document.createElement('span');
      if (await isExpandable(itemID)) {
        el.classList.add('directory');
      } else {
        el.classList.add('file');
      }
      const parts = itemID.split('/');
      el.textContent = parts[parts.length - 1];
      return el;
    }

    /* Returns true if there is at least one child item for given item ID. */
    async function isExpandable(itemID) {
      if (itemPaths.find(path => path.startsWith(`${itemID}/`))) {
        return true;
      }
      return false;
    }

    /* Returns a list of immediate child IDs. */
    async function getItemChildren(itemID) {
      const slashCount = (itemID.match(/\//ig) || []).length;
      return itemPaths.filter(path =>
        path.startsWith(`${itemID}/`) &&
        ((path.match(/\//ig) || []).length === slashCount + 1));
    }


    // Search

    const search = rootContainer.querySelector('[data-file-search]');
    let itemIDsPreSearch = null;

    if (search) {
      const initialSearchString = window.localStorage.getItem('search-string');
      if (initialSearchString) {
        search.value = initialSearchString;
        setTimeout(() => {
          handleSearch(initialSearchString);
        }, 1000);
      }

      function itemPathMatchesSearch(itemPath, searchString) {
        const pathParts = itemPath.split('/');
        return pathParts[pathParts.length - 1].toLowerCase().indexOf(searchString.toLowerCase()) >= 0;
      }

      function handleSearch(searchString) {
        localStorage.setItem('search-string', searchString);
        if (searchString.length >= 2) {
          if (!itemIDsPreSearch) {
            itemIDsPreSearch = listing.getItemIDs();
          }
          listing.updateItems(
            (() => itemPaths.filter(i => itemPathMatchesSearch(i, searchString))),
            true);
        } else {
          if (itemIDsPreSearch) {
            listing.updateItems((() => itemIDsPreSearch), true);
            itemIDsPreSearch = null;
          }
        }
      }

      search.addEventListener('keyup', function _handleSearch(evt) { handleSearch(evt.currentTarget.value) });
    }
  }

  document.addEventListener('DOMContentLoaded', initFileBrowser);

  /**
   * Aggregates parts (mapped to slash-separated paths) into a nested object.
   * E.g. `{ /some/path: A, /foo: B, /some/other/path: C }`
   * gets turned into `{ foo: B, some: { path: A, other: { path: C } } }`.
   */
  function unflattenObject(parts) {
      const result = {};

      for (const partPath of Object.keys(parts)) {
        if (Object.prototype.hasOwnProperty.call(parts, partPath)) {

          const keys = partPath.match(/^\/+[^\/]*|[^\/]*\/+$|(?:\/{2,}|[^\/])+(?:\/+$)?/g);
          // Matches a standalone slash in a key
          //const keys = partPath.match(/^\.+[^.]*|[^.]*\.+$|(?:\.{2,}|[^.])+(?:\.+$)?/g);

          if (keys) {
            keys.reduce((accumulator, val, idx) => {
              return accumulator[val] || (
                (accumulator[val] = isNaN(Number(keys[idx + 1]))
                  ? (keys.length - 1 === idx
                    ? parts[partPath]
                    : {})
                  : [])
              );
            }, result);
          }
        }
      }

      return result;
    }
})();
