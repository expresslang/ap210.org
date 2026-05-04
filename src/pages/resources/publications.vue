<script setup lang="ts">
import AnimatedSection from '@/components/ui/AnimatedSection.vue'
import Breadcrumbs from '@/components/content/Breadcrumbs.vue'

const publications = [
  {
    id: 'NIST AMS 100-51',
    title: 'On Migrating ISO 10303 PMI Models to a Common Core',
    authors: 'Allison Barnard Feeney and Thomas Thurman',
    year: '2020',
    description: 'Examines approaches for consolidating product manufacturing information (PMI) representations across STEP application protocols into a unified core model.',
    url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=935394',
  },
  {
    id: 'NIST AMS 300-12',
    title: 'Research Results and Recommendations for Universally Unique Identifiers',
    authors: 'NIST',
    year: '2019',
    description: 'Research findings and recommendations on the use of universally unique identifiers for product data management and traceability.',
    url: 'https://nvlpubs.nist.gov/nistpubs/ams/NIST.AMS.300-12.pdf',
  },
  {
    id: 'NIST GCR 15-990',
    title: 'Representation of Thermal Resistor Network Model for Packaged Component in STEP AP210 Edition 2',
    authors: 'Jamie Stori, Kevin Brady, and Thomas Thurman',
    year: '2015',
    description: 'Develops a thermal resistor network model for packaged electronic components, represented using STEP AP210 data structures for thermal management analysis.',
    url: 'https://www.nist.gov/publications/representation-thermal-resistor-network-model-packaged-component-step-ap210-edition-2',
  },
  {
    id: 'NIST GCR 15-991',
    title: 'Extensions of Recommended Practices for GD&T in STEP-AP210 in the Context of Packaged Electronic Components',
    authors: 'NIST',
    year: '2015',
    description: 'Extends geometric dimensioning and tolerancing (GD&T) recommended practices for use with STEP AP210, addressing the specific requirements of packaged electronic components.',
    url: 'https://www.nist.gov/publications/extensions-recommended-practices-gdt-step-ap210-context-packaged-electronic-components',
  },
  {
    id: 'NIST IR 6991',
    title: 'Representation of Thermal Resistor Network Model for a Packaged Component for Use in STEP AP210',
    authors: 'NIST',
    year: '2003',
    description: 'Defines how to represent thermal resistor network models for packaged components within the STEP AP210 information model, enabling thermal analysis data exchange.',
    url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=903903',
  },
  {
    id: 'NIST IR 7648',
    title: 'NIST IR 7648',
    authors: 'NIST',
    year: '2009',
    description: 'NIST Internal Report documenting AP210 research findings and implementation methodology.',
    url: 'https://doi.org/10.6028/NIST.IR.7648',
  },
  {
    id: 'PLM Requirements',
    title: 'Requirements on Information Technology for Product Lifecycle Management',
    authors: 'Peter Denno (NIST) and Thomas Thurman (Rockwell Collins)',
    year: '2004',
    description: 'Analyzes the requirements for information technology supporting product lifecycle management, focusing on data cohesion, traceability, and process-aware integration schema — with AP210 as a case study.',
    url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=822191',
  },
  {
    id: 'INCOSE MBSE',
    title: 'On Enabling a Model-Based Systems Engineering Discipline',
    authors: 'Peter Denno (NIST), Thomas Thurman (Rockwell Collins), John Mettenburg (Rockwell Collins), and Dwayne Hardy (American Systems)',
    year: '2007',
    description: 'Presents a methodology for model-based systems engineering that integrates STEP standards including AP210, demonstrating how electronic design data supports systems engineering workflows.',
    url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=824653',
  },
  {
    id: 'NIST IR 7677',
    title: 'AP210 Edition 2 Concept of Operations',
    authors: 'Jamie Stori (SFM Technology) and Kevin Brady (NIST)',
    year: '2009',
    description: 'Defines the concept of operations for AP210 Edition 2, describing the operational framework, use cases, and data exchange scenarios the standard addresses.',
    url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=905123',
  },
  {
    id: 'NIST IR 7717',
    title: 'Use Cases for the Management and Maintenance of Multi-Domain AP210 Component Models',
    authors: 'NIST',
    year: '2010',
    description: 'Documents use cases for managing AP210 component models across multiple engineering domains, addressing model maintenance, versioning, and cross-domain consistency.',
    url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=906355',
  },
]
</script>

<template>
  <div class="max-w-5xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <Breadcrumbs />

    <AnimatedSection>
      <div class="mb-12">
        <p class="font-mono text-xs tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue mb-3">Resources</p>
        <h1 class="text-3xl sm:text-4xl font-serif font-bold text-gray-900 dark:text-white">Reference Publications</h1>
        <p class="mt-4 text-gray-500 dark:text-gray-400 max-w-2xl leading-relaxed">
          Key NIST and INCOSE publications documenting AP 210 research, methodology, and the development of standards for electronic design data exchange.
        </p>
      </div>
    </AnimatedSection>

    <AnimatedSection>
      <div class="space-y-4">
        <a
          v-for="pub in publications"
          :key="pub.id"
          :href="pub.url"
          target="_blank"
          rel="noopener"
          class="block rounded-xl border border-gray-200/80 dark:border-gray-700/60 bg-white dark:bg-navy-light p-5 hover:border-elf-blue/30 dark:hover:border-elf-blue/30 hover:shadow-lg hover:shadow-elf-blue/5 dark:hover:shadow-elf-blue/5 hover:-translate-y-0.5 transition-all duration-200 group"
        >
          <div class="flex items-start gap-4">
            <div class="shrink-0 mt-0.5">
              <div class="w-14 h-14 rounded-lg bg-elf-blue/8 dark:bg-elf-blue/10 flex flex-col items-center justify-center">
                <span class="font-mono text-[0.6rem] tracking-wider text-gray-400 dark:text-gray-500 leading-none">{{ pub.year }}</span>
                <span class="text-xs font-bold text-elf-blue dark:text-elf-blue mt-0.5">PDF</span>
              </div>
            </div>
            <div class="min-w-0 flex-1">
              <div class="flex items-start justify-between gap-3">
                <div class="min-w-0">
                  <span class="inline-block font-mono text-[0.6rem] tracking-wider text-gray-400 dark:text-gray-500 bg-gray-50 dark:bg-gray-800/60 px-2 py-0.5 rounded-md mb-2">{{ pub.id }}</span>
                  <h3 class="font-serif font-bold text-gray-900 dark:text-white group-hover:text-elf-blue transition-colors leading-snug">{{ pub.title }}</h3>
                </div>
                <svg class="w-5 h-5 text-gray-300 dark:text-gray-600 group-hover:text-elf-blue shrink-0 mt-1 transition-colors" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10 6H6a2 2 0 00-2 2v10a2 2 0 002 2h10a2 2 0 002-2v-4M14 4h6m0 0v6m0-6L10 14"/></svg>
              </div>
              <p class="text-sm text-gray-500 dark:text-gray-400 mt-1">{{ pub.authors }}</p>
              <p class="text-sm text-gray-600 dark:text-gray-300 mt-2 leading-relaxed">{{ pub.description }}</p>
            </div>
          </div>
        </a>
      </div>
    </AnimatedSection>
  </div>
</template>
