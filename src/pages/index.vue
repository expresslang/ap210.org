<script setup lang="ts">
import AnimatedSection from '@/components/ui/AnimatedSection.vue'
import BaseButton from '@/components/ui/BaseButton.vue'
import BaseCard from '@/components/ui/BaseCard.vue'

const stats = [
  { label: 'Standard Editions', value: '4' },
  { label: 'Research Projects', value: '7' },
  { label: 'Test Cases', value: '36' },
  { label: 'Course Lessons', value: '44' },
]

const sections = [
  {
    title: 'Learn',
    description: 'Structured courses from STEP fundamentals to programming with AP 210 data.',
    to: '/learn',
    icon: 'M12 6.253v13m0-13C10.832 5.477 9.246 5 7.5 5S4.168 5.477 3 6.253v13C4.168 18.477 5.754 18 7.5 18s3.332.477 4.5 1.253m0-13C13.168 5.477 14.754 5 16.5 5c1.747 0 3.332.477 4.5 1.253v13C19.832 18.477 18.247 18 16.5 18c-1.746 0-3.332.477-4.5 1.253',
  },
  {
    title: 'Application',
    description: 'Concept of operations, recommended practices, and terminology for AP 210.',
    to: '/application',
    icon: 'M19.428 15.428a2 2 0 00-1.022-.547l-2.387-.477a6 6 0 00-3.86.517l-.318.158a6 6 0 01-3.86.517L6.05 15.21a2 2 0 00-1.806.547M8 4h8l-1 1v5.172a2 2 0 00.586 1.414l5 5c1.26 1.26.367 3.414-1.415 3.414H4.828c-1.782 0-2.674-2.154-1.414-3.414l5-5A2 2 0 009 10.172V5L8 4z',
  },
  {
    title: 'Research',
    description: 'NIST and PDES Inc. collaborative research projects and datasets.',
    to: '/research',
    icon: 'M21 12a9 9 0 01-9 9m9-9a9 9 0 00-9-9m9 9H3m9 9a9 9 0 01-9-9m9 9c1.657 0 3-4.03 3-9s-1.343-9-3-9m0 18c-1.657 0-3-4.03-3-9s1.343-9 3-9m-9 9a9 9 0 019-9',
  },
  {
    title: 'Resources',
    description: 'Test cases, Javadoc API, EXPRESS schema, and implementation tools.',
    to: '/resources',
    icon: 'M4 7v10c0 2.21 3.582 4 8 4s8-1.79 8-4V7M4 7c0 2.21 3.582 4 8 4s8-1.79 8-4M4 7c0-2.21 3.582-4 8-4s8 1.79 8 4',
  },
]

const editions = [
  { n: 1, year: '2001', desc: 'First publication' },
  { n: 2, year: '2006', desc: 'Expanded scope' },
  { n: 3, year: '2014', desc: 'Major revision' },
  { n: 4, year: '2021', desc: 'Current edition' },
]

const heroCode = `SCHEMA AP210_Electronic_Assembly;
ENTITY product;
  id : STRING;
  geometry : shape_representation;
  components : LIST OF assembly_component;
END_ENTITY;

ENTITY assembly_component;
  part : physical_design;
  placement : item_defined_transformation;
  connectivity : interconnect_module_interface;
END_ENTITY;
END_SCHEMA;`
</script>

<template>
  <div>
    <!-- Hero -->
    <section class="relative overflow-hidden bg-gradient-to-b from-slate-50 to-white dark:from-navy dark:to-navy-light/30">
      <div class="absolute inset-0 pointer-events-none">
        <div class="absolute top-20 right-[10%] w-[500px] h-[500px] rounded-full bg-elf-blue/[0.03] dark:bg-elf-blue/[0.03] blur-3xl" />
        <div class="absolute bottom-0 left-[5%] w-[300px] h-[300px] rounded-full bg-elf-salmon/[0.04] dark:bg-elf-blue/[0.02] blur-3xl" />
      </div>

      <div class="relative max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 pt-20 pb-20 lg:pt-28 lg:pb-28">
        <div class="flex flex-col lg:flex-row items-start gap-12 lg:gap-16">
          <div class="max-w-xl flex-1 min-w-0">
            <div class="flex items-center gap-3 mb-5">
              <p class="font-mono text-xs tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue">
                ISO 10303-210
              </p>
              <span class="text-[0.6rem] font-mono font-semibold tracking-wider uppercase px-2 py-0.5 rounded-full border border-elf-blue/30 dark:border-elf-blue/40 text-elf-blue dark:text-elf-blue bg-elf-blue/5 dark:bg-elf-blue/10">International Standard</span>
            </div>
            <h1 class="text-4xl sm:text-5xl lg:text-[3.5rem] font-serif font-bold text-gray-900 dark:text-white leading-[1.15] tracking-tight">
              Electronic Assembly,<br />
              Interconnect &amp;<br />
              <span class="text-elf-blue dark:text-elf-blue">Packaging Design</span>
            </h1>
            <p class="mt-6 text-lg text-gray-600 dark:text-gray-300 leading-relaxed max-w-lg">
              The international standard for representing and exchanging electronic design data
              — from component libraries to PCB layout to complete product assembly.
            </p>
            <div class="mt-8 flex flex-wrap gap-3">
              <BaseButton to="/learn" size="lg">
                <svg class="w-4 h-4" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M13 10V3L4 14h7v7l9-11h-7z"/></svg>
                Start Learning
              </BaseButton>
              <BaseButton to="/about" variant="secondary" size="lg">
                About AP 210
              </BaseButton>
            </div>

            <div class="mt-10 flex gap-8 text-sm">
              <div v-for="stat in stats" :key="stat.label">
                <p class="font-mono text-2xl font-bold text-elf-blue dark:text-elf-blue">{{ stat.value }}</p>
                <p class="text-gray-500 dark:text-gray-400 mt-0.5">{{ stat.label }}</p>
              </div>
            </div>
          </div>

          <!-- Code card -->
          <div class="flex items-start justify-center w-full lg:w-[420px] shrink-0 mt-8 lg:mt-10">
            <div class="w-full rounded-2xl border border-gray-200/60 dark:border-gray-700/40 bg-white dark:bg-navy-light shadow-2xl shadow-elf-blue/5 dark:shadow-black/20 overflow-hidden">
              <div class="flex items-center gap-2 px-4 py-2.5 border-b border-gray-100 dark:border-gray-700/40 bg-gray-50/80 dark:bg-navy">
                <span class="w-2.5 h-2.5 rounded-full bg-red-400/70" />
                <span class="w-2.5 h-2.5 rounded-full bg-amber-400/70" />
                <span class="w-2.5 h-2.5 rounded-full bg-emerald-400/70" />
                <span class="ml-2 text-[0.7rem] font-mono text-gray-400 dark:text-gray-500">ap210_schema.exp</span>
              </div>
              <div class="p-5 font-mono text-[0.8rem] leading-[1.8] whitespace-pre text-gray-700 dark:text-gray-300">{{ heroCode }}</div>
            </div>
          </div>
        </div>
      </div>
    </section>

    <!-- Section cards -->
    <section class="py-24 bg-white dark:bg-navy">
      <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <AnimatedSection>
          <div class="text-center mb-16">
            <p class="font-mono text-xs tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue mb-3">Explore</p>
            <h2 class="text-3xl font-serif font-bold text-gray-900 dark:text-white">Everything AP 210</h2>
            <p class="mt-3 text-gray-500 dark:text-gray-400 max-w-xl mx-auto">
              Education, application guidance, research data, and reference implementations for the electronic assembly standard.
            </p>
          </div>
        </AnimatedSection>

        <div class="grid sm:grid-cols-2 lg:grid-cols-4 gap-5">
          <AnimatedSection v-for="(section, i) in sections" :key="section.title" :style="{ transitionDelay: `${i * 60}ms` }">
            <BaseCard :to="section.to" padding="lg">
              <div class="w-12 h-12 rounded-xl bg-elf-blue/8 dark:bg-elf-blue/8 flex items-center justify-center mb-5">
                <svg class="w-6 h-6 text-elf-blue dark:text-elf-blue" fill="none" stroke="currentColor" stroke-width="1.5" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" :d="section.icon"/></svg>
              </div>
              <h3 class="font-serif font-bold text-xl text-gray-900 dark:text-white mb-2">{{ section.title }}</h3>
              <p class="text-sm text-gray-500 dark:text-gray-400 leading-relaxed">{{ section.description }}</p>
              <span class="mt-4 inline-flex items-center text-sm font-medium text-elf-blue dark:text-elf-blue">
                Explore
                <svg class="w-3.5 h-3.5 ml-1" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 5l7 7-7 7"/></svg>
              </span>
            </BaseCard>
          </AnimatedSection>
        </div>
      </div>
    </section>

    <!-- Standards editions -->
    <section class="py-20 bg-gray-50 dark:bg-navy-light/30">
      <div class="max-w-5xl mx-auto px-4 sm:px-6 lg:px-8">
        <AnimatedSection>
          <div class="text-center mb-14">
            <p class="font-mono text-xs tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue mb-3">Evolution</p>
            <h2 class="text-3xl font-serif font-bold text-gray-900 dark:text-white">Four editions of the standard</h2>
            <p class="mt-3 text-gray-500 dark:text-gray-400 max-w-lg mx-auto">
              ISO 10303-210 has evolved through four editions spanning two decades, each expanding scope and capability.
            </p>
          </div>
        </AnimatedSection>

        <div class="relative">
          <div class="absolute left-4 sm:left-8 top-0 bottom-0 w-px bg-gradient-to-b from-elf-blue/30 via-elf-blue/10 to-transparent dark:from-elf-blue/30 dark:via-elf-blue/10" />
          <div class="space-y-8">
            <AnimatedSection v-for="(ed, i) in editions" :key="ed.n" :style="{ transitionDelay: `${i * 80}ms` }">
              <RouterLink :to="`/standard/ed${ed.n}`" class="relative flex items-start gap-6 sm:gap-8 group">
                <div class="relative z-10 shrink-0">
                  <div class="w-8 sm:w-16 h-8 sm:h-16 rounded-full bg-white dark:bg-navy-light border-2 border-elf-blue/30 dark:border-elf-blue/30 flex items-center justify-center group-hover:border-elf-blue dark:group-hover:border-elf-blue transition-colors">
                    <span class="font-mono text-xs sm:text-sm font-bold text-elf-blue dark:text-elf-blue">{{ ed.year }}</span>
                  </div>
                </div>
                <div class="pt-1 sm:pt-4">
                  <p class="font-serif font-bold text-gray-900 dark:text-white group-hover:text-elf-blue transition-colors">Edition {{ ed.n }}</p>
                  <p class="text-sm text-gray-500 dark:text-gray-400 mt-0.5">{{ ed.desc }}</p>
                </div>
              </RouterLink>
            </AnimatedSection>
          </div>
        </div>
      </div>
    </section>

    <!-- CTA -->
    <section class="relative overflow-hidden py-24 bg-elf-blue dark:bg-elf-blue-dark">
      <div class="absolute inset-0 pointer-events-none opacity-10">
        <svg viewBox="0 0 200 200" fill="none" class="absolute -right-20 top-0 w-96 h-96 text-white">
          <path d="M40 40L100 100L40 160" stroke="currentColor" stroke-width="8" fill="none" stroke-linecap="round"/>
          <path d="M160 40L100 100L160 160" stroke="currentColor" stroke-width="8" fill="none" stroke-linecap="round"/>
        </svg>
      </div>
      <div class="relative max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 text-center">
        <AnimatedSection>
          <h2 class="text-3xl font-serif font-bold text-white mb-4">Start building with AP 210</h2>
          <p class="text-blue-100 dark:text-gray-300 leading-relaxed max-w-2xl mx-auto mb-8">
            Whether you're implementing the standard, analyzing PCB designs, or building electronic design tools —
            our structured courses and reference materials will get you there.
          </p>
          <div class="flex flex-wrap justify-center gap-3">
            <BaseButton to="/learn" size="lg">
              Start Learning
            </BaseButton>
            <BaseButton to="/resources" variant="secondary" size="lg" class="!border-white/30 !text-white dark:!border-gray-500 dark:!text-gray-300 hover:!bg-white/10">
              Browse Resources
            </BaseButton>
          </div>
        </AnimatedSection>
      </div>
    </section>
  </div>
</template>
