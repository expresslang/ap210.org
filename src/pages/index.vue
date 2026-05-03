<script setup lang="ts">
</script>

<template>
  <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-24">
    <div class="text-center">
      <h1 class="text-4xl sm:text-5xl lg:text-6xl font-bold text-gray-900 dark:text-white tracking-tight">
        AP 210
      </h1>
      <p class="mt-4 text-xl text-gray-600 dark:text-gray-300 max-w-2xl mx-auto">
        ISO 10303-210 — Electronic Assembly, Interconnect and Packaging Design
      </p>
      <p class="mt-6 text-lg text-gray-500 dark:text-gray-400 max-w-3xl mx-auto">
        The international standard for representing and exchanging electronic design data,
        from PCB layout to component assembly.
      </p>
      <div class="mt-10 flex flex-wrap justify-center gap-4">
        <RouterLink
          to="/learn"
          class="inline-flex items-center px-6 py-3 bg-elf-blue text-white font-medium rounded-lg hover:bg-elf-blue/90 transition-colors"
        >
          Start Learning
        </RouterLink>
        <RouterLink
          to="/application"
          class="inline-flex items-center px-6 py-3 border border-gray-300 dark:border-gray-600 text-gray-700 dark:text-gray-300 font-medium rounded-lg hover:bg-gray-50 dark:hover:bg-navy-light transition-colors"
        >
          Application Docs
        </RouterLink>
      </div>

      <div class="mt-20 grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-6 text-left">
        <RouterLink to="/learn" class="p-6 rounded-xl border border-gray-200 dark:border-gray-700 hover:border-elf-blue dark:hover:border-elf-blue transition-colors group">
          <h3 class="font-semibold text-gray-900 dark:text-white group-hover:text-elf-blue transition-colors">Learn</h3>
          <p class="mt-2 text-sm text-gray-500 dark:text-gray-400">Structured courses from STEP fundamentals to programming with AP210 data.</p>
        </RouterLink>
        <RouterLink to="/application" class="p-6 rounded-xl border border-gray-200 dark:border-gray-700 hover:border-elf-blue dark:hover:border-elf-blue transition-colors group">
          <h3 class="font-semibold text-gray-900 dark:text-white group-hover:text-elf-blue transition-colors">Application</h3>
          <p class="mt-2 text-sm text-gray-500 dark:text-gray-400">Concept of operations, recommended practices, and terminology.</p>
        </RouterLink>
        <RouterLink to="/research" class="p-6 rounded-xl border border-gray-200 dark:border-gray-700 hover:border-elf-blue dark:hover:border-elf-blue transition-colors group">
          <h3 class="font-semibold text-gray-900 dark:text-white group-hover:text-elf-blue transition-colors">Research</h3>
          <p class="mt-2 text-sm text-gray-500 dark:text-gray-400">NIST and PDES Inc. collaborative research projects and datasets.</p>
        </RouterLink>
        <RouterLink to="/resources" class="p-6 rounded-xl border border-gray-200 dark:border-gray-700 hover:border-elf-blue dark:hover:border-elf-blue transition-colors group">
          <h3 class="font-semibold text-gray-900 dark:text-white group-hover:text-elf-blue transition-colors">Resources</h3>
          <p class="mt-2 text-sm text-gray-500 dark:text-gray-400">Test cases, Javadoc API, EXPRESS schema, and implementation tools.</p>
        </RouterLink>
      </div>
    </div>
  </div>
</template>
