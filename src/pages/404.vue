<script setup lang="ts">
import BaseButton from '@/components/ui/BaseButton.vue'
</script>

<template>
  <div class="flex items-center justify-center min-h-[60vh]">
    <div class="text-center px-4 py-24">
      <p class="font-mono text-sm tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue mb-3">Error</p>
      <h1 class="text-6xl font-serif font-bold text-gray-900 dark:text-white">404</h1>
      <p class="mt-4 text-xl text-gray-600 dark:text-gray-300 font-serif">Page not found</p>
      <p class="mt-2 text-gray-500 dark:text-gray-400 max-w-md mx-auto">The page you're looking for doesn't exist or has been moved.</p>
      <div class="mt-8">
        <BaseButton to="/" size="lg">
          <svg class="w-4 h-4" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M3 12l2-2m0 0l7-7 7 7M5 10v10a1 1 0 001 1h3m10-11l2 2m-2-2v10a1 1 0 01-1 1h-3m-6 0a1 1 0 001-1v-4a1 1 0 011-1h2a1 1 0 011 1v4a1 1 0 001 1m-6 0h6"/></svg>
          Go Home
        </BaseButton>
      </div>
    </div>
  </div>
</template>
