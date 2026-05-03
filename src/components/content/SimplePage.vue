<script setup lang="ts">
import { useRoute } from 'vue-router'
import { useContent } from '@/composables/useContent'
import AsciiDocContent from '@/components/content/AsciiDocContent.vue'
import Breadcrumbs from '@/components/content/Breadcrumbs.vue'

const route = useRoute()
const slug = route.meta.contentSlug as string
const content = await useContent('pages', slug)
</script>

<template>
  <div class="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <Breadcrumbs />
    <AsciiDocContent v-if="content" :html="content.body" :title="content.title" />
    <p v-else class="text-gray-500">Content coming soon.</p>
  </div>
</template>
