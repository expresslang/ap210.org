<script setup lang="ts">
import { useRoute } from 'vue-router'
import { useContent } from '@/composables/useContent'
import AsciiDocContent from '@/components/content/AsciiDocContent.vue'

const route = useRoute()
const slug = route.params.slug as string
const content = await useContent('posts', slug)
</script>

<template>
  <div class="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <div v-if="content" class="mb-6 text-sm text-gray-500 dark:text-gray-400">
      <RouterLink to="/blog" class="hover:text-elf-blue dark:hover:text-elf-blue transition-colors">&larr; Blog</RouterLink>
    </div>
    <AsciiDocContent v-if="content" :body="content.body" :title="content.title" :date="content.date" :authors="content.authors" />
    <p v-else class="text-gray-500">Post not found.</p>
  </div>
</template>
