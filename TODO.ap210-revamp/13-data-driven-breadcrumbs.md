# TODO 13: Data-driven breadcrumbs

## Problem
Breadcrumbs use a static `labelMap` for ALL page names. This means:
- Adding a lesson requires updating Breadcrumbs.vue (violates open/closed)
- Lesson pages show generic route meta title ("Foundations") instead of actual lesson title ("Introduction to STEP")
- 30+ entries in a hardcoded map that duplicates data already in navigationMap

## Solution
Rewrite Breadcrumbs.vue to resolve titles from navigationMap (the single source of truth):
1. Search navigationMap for matching slug or path
2. Small static map for section-level labels only (about → About, learn → Learn, etc.)
3. Prettified slug as final fallback

## Result
- Zero duplication: page titles come from navigation.ts
- Open/closed: adding lessons to navigation.ts automatically fixes breadcrumbs
- Accurate: "Introduction to STEP" instead of "Foundations"
