# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

AP 210 website (https://www.ap210.org) — ISO 10303-210 Electronic Assembly, Interconnect and Packaging Design. Built with Vue 3 + ViteSSG (static site generation) + Tailwind CSS 4.

## Build & Development Commands

```bash
npm install                      # Install dependencies
npm run build:content            # Convert AsciiDoc content to JSON (scripts/build-content.ts)
npm run dev                      # Build content + start Vite dev server
npm run dev:watch                # Concurrent content watch + Vite dev server
npm run build                    # Full production build (content → SSG → sitemap)
npm run preview                  # Preview production build locally
```

## Architecture

**Framework:** Vue 3 with ViteSSG for static site generation. TypeScript throughout.

**Content pipeline:**
1. `.adoc` files in `content/` (with optional YAML frontmatter)
2. `scripts/build-content.ts` converts them to JSON in `src/content/` using `@asciidoctor/core` + `gray-matter`
3. `src/composables/useContent.ts` loads JSON via `import.meta.glob` (eager, at build time)
4. Page components call `useContent(section, slug)` to get content data

**Content sections** (each is a subdirectory in `content/`):
- `pages/` — Static pages (about, learn catalog, resources, privacy, tos)
- `posts/` — Blog posts (filename format: `YYYY-MM-DD-title.adoc`)
- `application/` — Application docs (concepts, recommended-practices, terms, examples)
- `standards/` — Standard editions (ed1–ed4)
- `research/` — Research project pages (7 projects)
- `foundations/` — Learn Module 1 (8 lessons)
- `ap210-concepts/` — Learn Module 2 (12 lessons)
- `reading-data/` — Learn Module 3 (8 lessons)
- `querying-data/` — Learn Module 4 (7 lessons)
- `programming/` — Learn Module 5 (9 lessons)

**Route-driven page rendering:** Most routes use two shared components driven by `route.meta`:
- `SectionPage.vue` — content + sidebar + optional lesson nav. Meta keys: `contentSection`, `contentSlug?`, `navKey`, `basePath`, `showLessonNav?`
- `SimplePage.vue` — content only, no sidebar. Meta key: `contentSlug` (loads from 'pages' section)

Custom pages (homepage, blog, learn catalog, 404) have their own components in `src/pages/`.

**Navigation:** Defined in `src/data/navigation.ts` — `mainNavigation` (top nav), per-section sidebar arrays, and `navigationMap` (keyed lookup used by SectionPage). NavItem supports both `path` (absolute) and `slug` (relative to basePath).

**Site config:** `src/data/site.ts` — title, URL, description, legal info.

**Key components:**
- `TheHeader.vue` / `TheFooter.vue` — Layout chrome (AP210-branded)
- `TheSidebar.vue` — Left sidebar with route-driven active state, supports both path-based and slug-based items
- `AsciiDocContent.vue` — Renders HTML with optional title/date/authors header
- `SectionPage.vue` / `SimplePage.vue` — Meta-driven page layouts
- `LessonNav.vue` — Prev/next navigation for learn modules

**Styles:** `src/styles/main.css` (Tailwind 4 with custom theme: `elf-blue`, `elf-salmon`, `navy`), `src/styles/asciidoc.css` (AsciiDoc HTML rendering).

## Adding New Content

1. Create `.adoc` file in the appropriate `content/` subdirectory
2. Add YAML frontmatter with `title` (and `date`, `excerpt` for blog posts)
3. If it's a new slug in an existing section, add route to `src/router.ts` with appropriate meta
4. If it needs sidebar navigation, add entry to the nav array in `src/data/navigation.ts`
5. Run `npm run build` to verify

## Deployment

- GitHub Actions deploys to GitHub Pages on push to `main`
- `.github/workflows/deploy.yml` — Node.js + ViteSSG build pipeline
- `.github/workflows/build.yml` — PR build verification
- Static assets in `public/` (images, Javadoc, ARM/MIM reference, test cases)
