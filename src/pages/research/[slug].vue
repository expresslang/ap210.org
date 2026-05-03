<script setup lang="ts">
import { useRoute } from 'vue-router'
import { useContent } from '@/composables/useContent'
import AsciiDocContent from '@/components/content/AsciiDocContent.vue'
import TheSidebar from '@/components/layout/TheSidebar.vue'
import { researchNavigation } from '@/data/navigation'

const route = useRoute()
const slug = route.params.slug as string
const content = await useContent('research', slug)
</script>

<template>
  <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <div class="lg:grid lg:grid-cols-[220px_1fr] lg:gap-10">
      <TheSidebar :items="researchNavigation" base-path="/research" />
      <div>
        <AsciiDocContent v-if="content" :body="content.body" :title="content.title" />
        <p v-else class="text-gray-500">Content coming soon.</p>
      </div>
    </div>
  </div>
</template>
