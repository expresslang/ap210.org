<script setup lang="ts">
import { useRoute } from 'vue-router'
import type { NavItem } from '@/data/navigation'
import { navigationMap } from '@/data/navigation'

const route = useRoute()

const sectionLabels: Record<string, string> = {
  about: 'About',
  standard: 'Standards',
  application: 'Application',
  research: 'Research',
  learn: 'Learn',
  resources: 'Resources',
  blog: 'Blog',
}

function findInItems(items: NavItem[], slug: string): string | null {
  for (const item of items) {
    if (item.slug === slug) return item.title
    if (item.path && (item.path === '/' + slug || item.path.endsWith('/' + slug))) return item.title
    if (item.children) {
      const found = findInItems(item.children, slug)
      if (found) return found
    }
  }
  return null
}

function resolveLabel(segment: string): string {
  for (const items of Object.values(navigationMap)) {
    const title = findInItems(items, segment)
    if (title) return title
  }
  if (sectionLabels[segment]) return sectionLabels[segment]
  return segment.replace(/[-_]/g, ' ').replace(/\b\w/g, c => c.toUpperCase())
}

interface Crumb { title: string; path: string }

const segments = route.path.split('/').filter(Boolean)
const crumbs: Crumb[] = segments.map((seg, i) => ({
  title: resolveLabel(seg),
  path: '/' + segments.slice(0, i + 1).join('/'),
}))
</script>

<template>
  <nav v-if="crumbs.length > 1" class="mb-6 text-sm text-gray-500 dark:text-gray-400" aria-label="Breadcrumb">
    <ol class="flex flex-wrap items-center gap-1">
      <li>
        <RouterLink to="/" class="hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Home</RouterLink>
      </li>
      <li v-for="(crumb, i) in crumbs" :key="crumb.path">
        <span class="mx-1 text-gray-300 dark:text-gray-600">/</span>
        <RouterLink
          v-if="i < crumbs.length - 1"
          :to="crumb.path"
          class="hover:text-elf-blue dark:hover:text-elf-blue transition-colors"
        >{{ crumb.title }}</RouterLink>
        <span v-else class="text-gray-700 dark:text-gray-300 font-medium">{{ crumb.title }}</span>
      </li>
    </ol>
  </nav>
</template>
