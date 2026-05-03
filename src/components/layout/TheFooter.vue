<script setup lang="ts">
import { siteData } from '@/data/site'
</script>

<template>
  <footer class="bg-gray-50 dark:bg-navy-light/50 border-t border-gray-200/60 dark:border-gray-800/60">
    <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-16">
      <div class="grid sm:grid-cols-2 lg:grid-cols-4 gap-10">
        <!-- Branding -->
        <div class="sm:col-span-2 lg:col-span-1">
          <RouterLink to="/" class="flex items-center gap-2.5 mb-4 group">
            <img src="/logos/logo-icon-white.svg" alt="AP 210" class="h-7 shrink-0 dark:hidden" />
            <img src="/logos/logo-icon-blue.svg" alt="AP 210" class="h-7 shrink-0 hidden dark:block" />
            <div class="flex flex-col leading-none">
              <span class="font-logo font-bold text-[0.8rem] tracking-[0.06em] text-elf-blue dark:text-white">AP 210</span>
              <span class="font-logo font-medium text-[0.5rem] tracking-[0.1em] text-elf-blue/70 dark:text-gray-400 mt-[2px]">ISO 10303-210</span>
            </div>
          </RouterLink>
          <p class="text-sm text-gray-500 dark:text-gray-400 leading-relaxed max-w-xs">
            International standard for electronic assembly, interconnect and packaging design data exchange.
          </p>
          <div class="flex items-center gap-3 mt-5">
            <a :href="siteData.github" target="_blank" rel="noopener" class="p-2 text-gray-400 hover:text-gray-600 dark:hover:text-gray-300 transition-colors rounded-md" aria-label="GitHub">
              <svg class="w-5 h-5" fill="currentColor" viewBox="0 0 24 24"><path d="M12 2C6.477 2 2 6.484 2 12.017c0 4.425 2.865 8.18 6.839 9.504.5.092.682-.217.682-.483 0-.237-.008-.868-.013-1.703-2.782.605-3.369-1.343-3.369-1.343-.454-1.158-1.11-1.466-1.11-1.466-.908-.62.069-.608.069-.608 1.003.07 1.531 1.032 1.531 1.032.892 1.53 2.341 1.088 2.91.832.092-.647.35-1.088.636-1.338-2.22-.253-4.555-1.113-4.555-4.951 0-1.093.39-1.988 1.029-2.688-.103-.253-.446-1.272.098-2.65 0 0 .84-.27 2.75 1.026A9.564 9.564 0 0112 6.844c.85.004 1.705.115 2.504.337 1.909-1.296 2.747-1.027 2.747-1.027.546 1.379.202 2.398.1 2.651.64.7 1.028 1.595 1.028 2.688 0 3.848-2.339 4.695-4.566 4.943.359.309.678.92.678 1.855 0 1.338-.012 2.419-.012 2.747 0 .268.18.58.688.482A10.019 10.019 0 0022 12.017C22 6.484 17.522 2 12 2z"/></svg>
            </a>
            <a :href="`mailto:${siteData.email}`" class="p-2 text-gray-400 hover:text-gray-600 dark:hover:text-gray-300 transition-colors rounded-md" aria-label="Email">
              <svg class="w-5 h-5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M3 8l7.89 5.26a2 2 0 002.22 0L21 8M5 19h14a2 2 0 002-2V7a2 2 0 00-2-2H5a2 2 0 00-2 2v10a2 2 0 002 2z"/></svg>
            </a>
          </div>
        </div>

        <!-- Content -->
        <div>
          <h3 class="font-mono text-xs font-semibold tracking-[0.15em] uppercase text-gray-400 dark:text-gray-500 mb-4">Content</h3>
          <ul class="space-y-2.5 text-sm">
            <li><RouterLink to="/application" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Application</RouterLink></li>
            <li><RouterLink to="/research" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Research</RouterLink></li>
            <li><RouterLink to="/standard" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Standards</RouterLink></li>
            <li><RouterLink to="/blog" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Blog</RouterLink></li>
          </ul>
        </div>

        <!-- Learning -->
        <div>
          <h3 class="font-mono text-xs font-semibold tracking-[0.15em] uppercase text-gray-400 dark:text-gray-500 mb-4">Learning</h3>
          <ul class="space-y-2.5 text-sm">
            <li><RouterLink to="/learn/foundations" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">STEP Foundations</RouterLink></li>
            <li><RouterLink to="/learn/ap210-concepts" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">AP210 Concepts</RouterLink></li>
            <li><RouterLink to="/learn/reading-data" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Reading Data</RouterLink></li>
            <li><RouterLink to="/learn/programming" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Programming</RouterLink></li>
          </ul>
        </div>

        <!-- Organization -->
        <div>
          <h3 class="font-mono text-xs font-semibold tracking-[0.15em] uppercase text-gray-400 dark:text-gray-500 mb-4">About</h3>
          <ul class="space-y-2.5 text-sm">
            <li><RouterLink to="/about" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">About AP 210</RouterLink></li>
            <li><RouterLink to="/about/team" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Team</RouterLink></li>
            <li><RouterLink to="/resources" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Resources</RouterLink></li>
            <li><RouterLink to="/privacy" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Privacy</RouterLink></li>
            <li><RouterLink to="/tos" class="text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue transition-colors">Terms of Service</RouterLink></li>
          </ul>
        </div>
      </div>

      <div class="mt-12 pt-8 border-t border-gray-200/60 dark:border-gray-800/60 flex flex-col sm:flex-row justify-between items-center gap-4 text-xs text-gray-400 dark:text-gray-500">
        <p>&copy; {{ new Date().getFullYear() }} {{ siteData.legal.name }}. All rights reserved.</p>
        <p class="font-mono tracking-wide">
          <span>ISO 10303-210 &mdash; Electronic Assembly, Interconnect and Packaging Design</span>
        </p>
      </div>
    </div>
  </footer>
</template>
