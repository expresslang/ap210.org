<script setup lang="ts">
import AnimatedSection from '@/components/ui/AnimatedSection.vue'
import BaseCard from '@/components/ui/BaseCard.vue'

const modules = [
  {
    title: 'STEP & EXPRESS Foundations',
    slug: 'foundations',
    description: 'Introduction to the STEP standard, the EXPRESS modeling language, and the business context for AP 210.',
    lessons: 8,
    prereqs: 'None',
    level: 'Beginner',
    icon: 'M12 6.253v13m0-13C10.832 5.477 9.246 5 7.5 5S4.168 5.477 3 6.253v13C4.168 18.477 5.754 18 7.5 18s3.332.477 4.5 1.253m0-13C13.168 5.477 14.754 5 16.5 5c1.747 0 3.332.477 4.5 1.253v13C19.832 18.477 18.247 18 16.5 18c-1.746 0-3.332.477-4.5 1.253',
    levelNum: 1,
  },
  {
    title: 'AP 210 Concepts',
    slug: 'ap210-concepts',
    description: 'Core AP 210 concepts including product structure, connectivity, physical design, and design rules.',
    lessons: 12,
    prereqs: 'Module 1',
    level: 'Intermediate',
    icon: 'M19.428 15.428a2 2 0 00-1.022-.547l-2.387-.477a6 6 0 00-3.86.517l-.318.158a6 6 0 01-3.86.517L6.05 15.21a2 2 0 00-1.806.547M8 4h8l-1 1v5.172a2 2 0 00.586 1.414l5 5c1.26 1.26.367 3.414-1.415 3.414H4.828c-1.782 0-2.674-2.154-1.414-3.414l5-5A2 2 0 009 10.172V5L8 4z',
    levelNum: 2,
  },
  {
    title: 'Reading AP 210 Data Files',
    slug: 'reading-data',
    description: 'Walk-throughs of AP 210 STEP files, from simple examples to complex multi-layer assemblies.',
    lessons: 8,
    prereqs: 'Module 2',
    level: 'Intermediate',
    icon: 'M9 12h6m-6 4h6m2 5H7a2 2 0 01-2-2V5a2 2 0 012-2h5.586a1 1 0 01.707.293l5.414 5.414a1 1 0 01.293.707V19a2 2 0 01-2 2z',
    levelNum: 2,
  },
  {
    title: 'Querying AP 210 Data',
    slug: 'querying-data',
    description: 'Using EXPRESS queries to extract information from AP 210 datasets.',
    lessons: 7,
    prereqs: 'Module 3',
    level: 'Advanced',
    icon: 'M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z',
    levelNum: 3,
  },
  {
    title: 'Programming with AP 210',
    slug: 'programming',
    description: 'Building applications with the JSDAI Java framework to work with AP 210 data.',
    lessons: 9,
    prereqs: 'Module 4',
    level: 'Advanced',
    icon: 'M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4',
    levelNum: 3,
  },
]

const levelColors: Record<string, string> = {
  Beginner: 'bg-green-100 text-green-700 dark:bg-green-900/30 dark:text-green-400',
  Intermediate: 'bg-amber-100 text-amber-700 dark:bg-amber-900/30 dark:text-amber-400',
  Advanced: 'bg-red-100 text-red-700 dark:bg-red-900/30 dark:text-red-400',
}
</script>

<template>
  <div>
    <!-- Hero -->
    <section class="bg-gradient-to-b from-slate-50 to-white dark:from-navy dark:to-navy-light/30">
      <div class="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 pt-16 pb-8">
        <p class="font-mono text-xs tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue mb-3">Course Catalog</p>
        <h1 class="text-3xl sm:text-4xl font-serif font-bold text-gray-900 dark:text-white tracking-tight">Learn AP 210</h1>
        <p class="mt-4 text-lg text-gray-600 dark:text-gray-300 max-w-2xl">
          Structured courses that take you from STEP fundamentals to building applications with AP 210 data.
          Each module builds on the previous one.
        </p>
      </div>
    </section>

    <!-- Modules -->
    <section class="py-16 bg-white dark:bg-navy">
      <div class="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8">
        <div class="space-y-6">
          <AnimatedSection v-for="(mod, i) in modules" :key="mod.slug" :style="{ transitionDelay: `${i * 60}ms` }">
            <BaseCard :to="`/learn/${mod.slug}`" padding="lg">
              <div class="flex flex-col sm:flex-row gap-5">
                <div class="flex items-center justify-center w-12 h-12 rounded-xl bg-elf-blue/8 dark:bg-elf-blue/8 shrink-0">
                  <span class="font-mono text-lg font-bold text-elf-blue dark:text-elf-blue">{{ mod.levelNum }}</span>
                </div>
                <div class="flex-1 min-w-0">
                  <div class="flex items-start justify-between gap-3">
                    <h2 class="font-serif font-bold text-lg text-gray-900 dark:text-white">{{ mod.title }}</h2>
                    <span :class="levelColors[mod.level]" class="px-2.5 py-0.5 rounded-full text-[0.7rem] font-semibold shrink-0">
                      {{ mod.level }}
                    </span>
                  </div>
                  <p class="mt-2 text-sm text-gray-600 dark:text-gray-400 leading-relaxed">{{ mod.description }}</p>
                  <div class="mt-4 flex flex-wrap items-center gap-4 text-xs text-gray-500 dark:text-gray-400">
                    <span class="flex items-center gap-1.5">
                      <svg class="w-3.5 h-3.5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 6.253v13m0-13C10.832 5.477 9.246 5 7.5 5S4.168 5.477 3 6.253v13C4.168 18.477 5.754 18 7.5 18s3.332.477 4.5 1.253m0-13C13.168 5.477 14.754 5 16.5 5c1.747 0 3.332.477 4.5 1.253v13C19.832 18.477 18.247 18 16.5 18c-1.746 0-3.332.477-4.5 1.253"/></svg>
                      {{ mod.lessons }} lessons
                    </span>
                    <span class="flex items-center gap-1.5">
                      <svg class="w-3.5 h-3.5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z"/></svg>
                      Prerequisites: {{ mod.prereqs }}
                    </span>
                  </div>
                </div>
              </div>
            </BaseCard>
          </AnimatedSection>
        </div>
      </div>
    </section>
  </div>
</template>
