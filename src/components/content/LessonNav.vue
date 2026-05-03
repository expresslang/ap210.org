<script setup lang="ts">
import type { NavItem } from '@/data/navigation'

const props = defineProps<{
  items: NavItem[]
  currentSlug: string
  basePath: string
}>()

function flatten(items: NavItem[]): NavItem[] {
  return items.flatMap(item => {
    if (item.children) return flatten(item.children)
    return item.slug ? [item] : []
  })
}

const flat = flatten(props.items)
const idx = flat.findIndex(i => i.slug === props.currentSlug)
const prev = idx > 0 ? flat[idx - 1] : null
const next = idx < flat.length - 1 ? flat[idx + 1] : null
</script>

<template>
  <nav v-if="prev || next" class="mt-12 pt-6 border-t border-gray-200 dark:border-gray-700 flex justify-between items-center">
    <RouterLink
      v-if="prev"
      :to="prev.slug === 'index' ? basePath : `${basePath}/${prev.slug}`"
      class="group flex items-center gap-2 text-sm font-medium text-gray-500 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors"
    >
      <svg class="w-4 h-4 transition-transform group-hover:-translate-x-0.5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 19l-7-7 7-7"/></svg>
      {{ prev.title }}
    </RouterLink>
    <span v-else />
    <RouterLink
      v-if="next"
      :to="next.slug === 'index' ? basePath : `${basePath}/${next.slug}`"
      class="group flex items-center gap-2 text-sm font-medium text-gray-500 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors"
    >
      {{ next.title }}
      <svg class="w-4 h-4 transition-transform group-hover:translate-x-0.5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5l7 7-7 7"/></svg>
    </RouterLink>
  </nav>
</template>
