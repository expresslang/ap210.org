<script setup lang="ts">
import { useRoute } from 'vue-router'
import { useContent } from '@/composables/useContent'
import AsciiDocContent from '@/components/content/AsciiDocContent.vue'
import TheSidebar from '@/components/layout/TheSidebar.vue'
import LessonNav from '@/components/content/LessonNav.vue'
import Breadcrumbs from '@/components/content/Breadcrumbs.vue'
import { navigationMap } from '@/data/navigation'

const route = useRoute()
const meta = route.meta as {
  contentSection: string
  contentSlug?: string
  navKey: string
  basePath: string
  showLessonNav?: boolean
}

const section = meta.contentSection
const slug = meta.contentSlug || (route.params.slug as string) || 'index'
const navItems = navigationMap[meta.navKey]
const content = await useContent(section, slug)
</script>

<template>
  <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <div class="lg:grid lg:grid-cols-[220px_1fr] lg:gap-10">
      <TheSidebar v-if="navItems" :items="navItems" :base-path="meta.basePath" />
      <div>
        <Breadcrumbs />
        <AsciiDocContent v-if="content" :html="content.body" :title="content.title" />
        <p v-else class="text-gray-500">Content coming soon.</p>
        <LessonNav v-if="meta.showLessonNav && navItems" :items="navItems" :current-slug="slug" :base-path="meta.basePath" />
      </div>
    </div>
  </div>
</template>
