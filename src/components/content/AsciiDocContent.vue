<script setup lang="ts">
defineProps<{
  html: string
  title?: string
  date?: string | null
  authors?: Array<{ name: string; email?: string; use_picture?: string }>
}>()

function formatDate(d: string) {
  return new Date(d).toLocaleDateString('en-US', { year: 'numeric', month: 'long', day: 'numeric' })
}
</script>

<template>
  <article class="asciidoc-content prose prose-gray dark:prose-invert max-w-none">
    <header v-if="title || date || authors?.length" class="mb-8 not-prose">
      <h1 v-if="title" class="text-3xl font-serif font-bold text-gray-900 dark:text-white tracking-tight">{{ title }}</h1>
      <div v-if="date || authors?.length" class="mt-3 flex flex-wrap items-center gap-3 text-sm text-gray-500 dark:text-gray-400">
        <time v-if="date" :datetime="date">{{ formatDate(date) }}</time>
        <span v-if="authors?.length">{{ authors.map(a => a.name).join(', ') }}</span>
      </div>
    </header>
    <div v-html="html" />
  </article>
</template>
