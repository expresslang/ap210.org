# TODO 1: Eliminate 30+ duplicate page components

## Problem
34 page components, ~24 are near-identical (sidebar + content + "coming soon"). Massive DRY violation.

## Solution
- Create `SectionPage.vue` (sidebar + content, driven by route meta)
- Create `SimplePage.vue` (content only, driven by route meta)
- Keep only custom pages: index, blog/*, learn/index, 404
- Rewrite router.ts with section config in route.meta
- Add `navigationMap` to navigation.ts for lookup by key
- Redesign TheSidebar to support both `path`-based and `slug`-based items
- Enhance AsciiDocContent with optional title/date/authors props (fixes blog rendering bug)
- Create `LessonNav.vue` for prev/next in learn modules

## Result: 7 page files instead of 34
