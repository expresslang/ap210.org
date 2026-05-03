# TODO 12: Resources section sidebar consistency

## Problem
Resources is the only section without sidebar navigation. Every other section (about, application, standards, research, learn) has a sidebar. This is inconsistent UX.

## Solution
- Create `resourcesNavigation` in navigation.ts
- Add to `navigationMap`
- Convert resource routes from SimplePage to SectionPage (except javadoc/arm-mim redirects)
- Breadcrumbs automatically work via navigationMap

## Pages affected
- /resources (overview) → SectionPage
- /resources/test-cases → SectionPage
- /resources/implementation → SectionPage
- /resources/express-schema → SectionPage
- /resources/discussions → SectionPage
- /resources/training-materials → SectionPage
- /resources/javadoc → redirect (unchanged)
- /resources/arm-mim-reference → redirect (unchanged)
