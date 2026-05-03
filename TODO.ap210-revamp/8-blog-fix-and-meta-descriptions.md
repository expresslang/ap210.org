# TODO 8: Fix blog rendering bug + add meta descriptions

## What
- Fix blog/[slug].vue — passes `:body` but AsciiDocContent expects `:html` prop
- Add description meta to all routes (only 7 of 87 have descriptions currently)

## Impact
- Blog post body content is silently dropped — nothing renders below the title
- SEO: search engines and social previews lack descriptions for most pages
