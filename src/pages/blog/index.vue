<script setup lang="ts">
import { useContentList } from '@/composables/useContent'
import BlogPostCard from '@/components/content/BlogPostCard.vue'

const posts = await useContentList('posts')
</script>

<template>
  <div class="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <h1 class="text-3xl font-bold text-gray-900 dark:text-white mb-8">Blog</h1>
    <div v-if="posts.length" class="space-y-6">
      <BlogPostCard v-for="post in posts" :key="post.slug" :post="post" />
    </div>
    <p v-else class="text-gray-500">No posts yet.</p>
  </div>
</template>
