<script setup lang="ts">
import { useContent } from '@/composables/useContent'
import AsciiDocContent from '@/components/content/AsciiDocContent.vue'

const content = await useContent('pages', 'resources-training-materials')
</script>

<template>
  <div class="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <AsciiDocContent v-if="content" :body="content.body" :title="content.title" />
    <p v-else class="text-gray-500">Content coming soon.</p>
  </div>
</template>
