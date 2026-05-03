<script setup lang="ts">
import { useContent } from '@/composables/useContent'
import AsciiDocContent from '@/components/content/AsciiDocContent.vue'
import TheSidebar from '@/components/layout/TheSidebar.vue'
import { queryingDataNavigation } from '@/data/navigation'

const content = await useContent('querying-data', 'index')
</script>

<template>
  <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <div class="lg:grid lg:grid-cols-[220px_1fr] lg:gap-10">
      <TheSidebar :items="queryingDataNavigation" base-path="/learn/querying-data" />
      <div>
        <AsciiDocContent v-if="content" :body="content.body" :title="content.title" />
        <p v-else class="text-gray-500">Content coming soon.</p>
      </div>
    </div>
  </div>
</template>
