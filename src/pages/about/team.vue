<script setup lang="ts">
import AnimatedSection from '@/components/ui/AnimatedSection.vue'
import BaseCard from '@/components/ui/BaseCard.vue'
import Breadcrumbs from '@/components/content/Breadcrumbs.vue'

interface Contributor {
  name: string
  role: string
  affiliation: string
  highlights: string[]
  publications?: { label: string; url: string }[]
}

interface ContributorGroup {
  category: string
  description: string
  people: Contributor[]
}

const contributors: ContributorGroup[] = [
  {
    category: 'Standards Leadership',
    description: 'Led the development, editorial work, and strategic direction of AP 210 across all four editions.',
    people: [
      {
        name: 'Thomas Thurman',
        role: 'AP 210 Project Leader',
        affiliation: 'PDES Inc. / Rockwell Collins',
        highlights: [
          'Led editorial development of all four editions of ISO 10303-210',
          'Authored the ARM and MIM EXPRESS schemas (38 modules)',
          'Created the AP 210 Training CD (July 2003)',
          'Directed the AP 210 Rules Model design process',
          'Authored multiple PDES test cases and annotated STEP examples',
        ],
        publications: [
          { label: 'NIST AMS 100-51', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=935394' },
          { label: 'Thermal Resistor Network (GCR 15-990)', url: 'https://www.nist.gov/publications/representation-thermal-resistor-network-model-packaged-component-step-ap210-edition-2' },
          { label: 'PLM Requirements', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=822191' },
          { label: 'MBSE (INCOSE)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=824653' },
          { label: 'Multi-Domain Component Models (IR 7717)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=906355' },
        ],
      },
      {
        name: 'Allison Barnard Feeney',
        role: 'General Manager, PDES Inc.',
        affiliation: 'PDES Inc. / NIST',
        highlights: [
          'Led NIST research on product manufacturing information (PMI) in STEP',
          'Co-authored research on migrating PMI models to a common core',
          'Advanced standards methodology for STEP interoperability',
          'Guided NIST research partnerships with PDES Inc. and industry',
        ],
        publications: [
          { label: 'NIST AMS 100-51', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=935394' },
        ],
      },
      {
        name: 'Kevin Brady',
        role: 'Research & Engineering',
        affiliation: 'National Institute of Standards and Technology',
        highlights: [
          'Research and engineering leadership for STEP standards at NIST',
          'Co-authored AP210 Ed2 Concept of Operations (NISTIR 7677)',
          'Co-authored thermal resistor network model research (GCR 15-990)',
          'Directed NIST programs supporting STEP implementation',
        ],
        publications: [
          { label: 'Concept of Operations (IR 7677)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=905123' },
          { label: 'Thermal Resistor Network (GCR 15-990)', url: 'https://www.nist.gov/publications/representation-thermal-resistor-network-model-packaged-component-step-ap210-edition-2' },
        ],
      },
    ],
  },
  {
    category: 'Research & Engineering',
    description: 'Developed reference implementations, analytical models, and research foundations for AP 210.',
    people: [
      {
        name: 'Peter Denno',
        role: 'Computer Scientist',
        affiliation: 'National Institute of Standards and Technology',
        highlights: [
          'Co-authored PLM requirements analysis for product lifecycle management',
          'Co-authored MBSE research connecting AP210 with systems engineering',
          'Developed process-aware integration schema concepts',
          'Contributed to EXPRESS-X mapping language (ISO 10303-14)',
          'Advanced AP233/SysML integration with STEP data',
        ],
        publications: [
          { label: 'PLM Requirements', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=822191' },
          { label: 'MBSE (INCOSE)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=824653' },
        ],
      },
      {
        name: 'Michael Keenan',
        role: 'Research Engineer',
        affiliation: 'NIST / Boeing',
        highlights: [
          'Developed the NIST JSDAI reference implementation for AP210',
          'Built the MIMqueries interface and model traversal APIs',
          'Created validation tools and test infrastructure',
          'Contributed to test case development for PDES Test Cases Project',
        ],
      },
      {
        name: 'Jamie Stori',
        role: 'AP210 Conceptual Framework',
        affiliation: 'SFM Technology, Inc.',
        highlights: [
          'Authored AP210 Edition 2 Concept of Operations (NISTIR 7677)',
          'Co-authored thermal resistor network model for packaged components',
          'Defined the operational framework for the standard',
        ],
        publications: [
          { label: 'Concept of Operations (IR 7677)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=905123' },
          { label: 'Thermal Resistor Network (GCR 15-990)', url: 'https://www.nist.gov/publications/representation-thermal-resistor-network-model-packaged-component-step-ap210-edition-2' },
        ],
      },
    ],
  },
  {
    category: 'Industry & Systems Engineering',
    description: 'Applied AP 210 in real-world engineering environments and advanced model-based systems engineering.',
    people: [
      {
        name: 'John Mettenburg',
        role: 'Principal Systems Engineer',
        affiliation: 'Rockwell Collins (now Collins Aerospace)',
        highlights: [
          'Co-authored MBSE research demonstrating AP210 in systems engineering workflows',
          'Bridged AP210 data standards with MBSE practices at Rockwell Collins',
          'Contributed to practical validation of AP210 in aerospace environments',
        ],
        publications: [
          { label: 'MBSE (INCOSE)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=824653' },
        ],
      },
      {
        name: 'Dwayne Hardy',
        role: 'Systems Engineer',
        affiliation: 'American Systems',
        highlights: [
          'Co-authored MBSE research connecting STEP standards with systems engineering',
          'Contributed to analysis of AP210 support for SE data integration',
        ],
        publications: [
          { label: 'MBSE (INCOSE)', url: 'https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=824653' },
        ],
      },
      {
        name: 'Gregory L. Smith',
        role: 'Design Rule Formalism',
        affiliation: 'The Boeing Company',
        highlights: [
          'Chaired AP210 design rule formalism discussions with Thurman and Bajaj',
          'Advanced constraint representation for electronic assembly design rules',
        ],
      },
      {
        name: 'Manas Bajaj',
        role: 'DFM Research',
        affiliation: 'Georgia Tech',
        highlights: [
          'Contributed to design-for-manufacturability frameworks via AP210',
          'Participated in design rule formalism discussions',
        ],
      },
    ],
  },
]

const testContributors = [
  { name: 'James F. Adams', affiliation: 'The Boeing Company', note: 'PDES-181 Complex Multi-layer PCA' },
  { name: 'Steve Waterbury', affiliation: 'NASA', note: 'Test cases and PLM research' },
  { name: 'Mike Benda', affiliation: '', note: 'Recommended practices' },
  { name: 'Jim Evans', affiliation: '', note: 'PDES test cases' },
  { name: 'Kevin Cline', affiliation: '', note: 'PDES test cases' },
  { name: 'Craig Lanning', affiliation: '', note: 'PDES test cases' },
  { name: 'Paul Monson', affiliation: '', note: 'PDES test cases' },
]

const organizations = [
  {
    name: 'NIST',
    full: 'National Institute of Standards and Technology',
    url: 'https://www.nist.gov',
    contributions: [
      'CFD analysis for thermal management',
      'Geometric Dimensioning and Tolerancing (GDT) for connectors and packages',
      'SPICE integration with AP210 mechanical design models',
      'JSDAI reference implementation and validation test cases',
    ],
  },
  {
    name: 'PDES Inc.',
    full: 'PDES Inc.',
    url: 'https://pdesinc.org',
    contributions: [
      'AP210 Viewer development and testing',
      'IDF-to-AP210 conversion tools',
      'Training materials and educational resources',
      'Standards validation and test case development',
    ],
  },
  {
    name: 'ISO TC 184/SC 4',
    full: 'ISO Technical Committee 184, Subcommittee 4',
    url: '',
    contributions: [
      'Governs the entire STEP (ISO 10303) family of standards',
      'Develops and maintains AP 210 under the Industrial data subcommittee',
    ],
  },
]
</script>

<template>
  <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
    <Breadcrumbs />

    <!-- Header -->
    <AnimatedSection>
      <div class="text-center mb-16">
        <p class="font-mono text-xs tracking-[0.2em] uppercase text-elf-blue dark:text-elf-blue mb-3">People & Organizations</p>
        <h1 class="text-3xl sm:text-4xl font-serif font-bold text-gray-900 dark:text-white">Team & Acknowledgments</h1>
        <p class="mt-4 text-gray-500 dark:text-gray-400 max-w-2xl mx-auto leading-relaxed">
          AP 210 is the product of decades of collaborative work by researchers, engineers, and standards professionals
          from industry, government, and academia.
        </p>
      </div>
    </AnimatedSection>

    <!-- Key Contributors — grouped by category -->
    <section v-for="(group, gi) in contributors" :key="group.category" class="mb-20">
      <AnimatedSection>
        <div class="mb-8">
          <h2 class="text-2xl font-serif font-bold text-gray-900 dark:text-white">{{ group.category }}</h2>
          <p class="mt-2 text-sm text-gray-500 dark:text-gray-400 max-w-2xl">{{ group.description }}</p>
        </div>
      </AnimatedSection>

      <div class="grid md:grid-cols-2 lg:grid-cols-3 gap-5">
        <AnimatedSection v-for="(person, pi) in group.people" :key="person.name" :style="{ transitionDelay: `${(gi * 3 + pi) * 60}ms` }">
          <BaseCard :padding="'lg'" :hover="false">
            <div class="flex items-start gap-4 mb-4">
              <div class="w-12 h-12 rounded-full bg-elf-blue/10 dark:bg-elf-blue/15 flex items-center justify-center shrink-0">
                <span class="text-lg font-serif font-bold text-elf-blue dark:text-elf-blue">{{ person.name.split(' ').map(w => w[0]).join('') }}</span>
              </div>
              <div class="min-w-0">
                <h3 class="font-serif font-bold text-gray-900 dark:text-white text-lg leading-tight">{{ person.name }}</h3>
                <p class="text-sm text-elf-blue dark:text-elf-blue font-medium">{{ person.role }}</p>
                <p class="text-xs text-gray-400 dark:text-gray-500 mt-0.5">{{ person.affiliation }}</p>
              </div>
            </div>

            <ul class="space-y-1.5 mb-4">
              <li v-for="h in person.highlights" :key="h" class="text-sm text-gray-600 dark:text-gray-300 flex items-start gap-2 leading-snug">
                <span class="w-1.5 h-1.5 rounded-full bg-elf-blue/40 dark:bg-elf-blue/30 shrink-0 mt-1.5" />
                {{ h }}
              </li>
            </ul>

            <div v-if="person.publications?.length" class="pt-3 border-t border-gray-100 dark:border-gray-700/40">
              <p class="text-[0.65rem] font-mono uppercase tracking-wider text-gray-400 dark:text-gray-500 mb-2">Publications</p>
              <div class="flex flex-wrap gap-1.5">
                <a
                  v-for="pub in person.publications"
                  :key="pub.label"
                  :href="pub.url"
                  target="_blank"
                  rel="noopener"
                  class="inline-flex items-center text-xs px-2 py-1 rounded-md bg-gray-50 dark:bg-gray-800/60 text-gray-600 dark:text-gray-400 hover:text-elf-blue dark:hover:text-elf-blue hover:bg-elf-blue/5 dark:hover:bg-elf-blue/10 transition-colors"
                >
                  {{ pub.label }}
                  <svg class="w-3 h-3 ml-1 opacity-50" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10 6H6a2 2 0 00-2 2v10a2 2 0 002 2h10a2 2 0 002-2v-4M14 4h6m0 0v6m0-6L10 14"/></svg>
                </a>
              </div>
            </div>
          </BaseCard>
        </AnimatedSection>
      </div>
    </section>

    <!-- Test Case & Training Contributors -->
    <section class="mb-20">
      <AnimatedSection>
        <div class="mb-8">
          <h2 class="text-2xl font-serif font-bold text-gray-900 dark:text-white">Test Cases & Training</h2>
          <p class="mt-2 text-sm text-gray-500 dark:text-gray-400 max-w-2xl">Contributors to PDES test cases, recommended practices, and training materials.</p>
        </div>
      </AnimatedSection>

      <AnimatedSection>
        <div class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 gap-3">
          <div
            v-for="tc in testContributors"
            :key="tc.name"
            class="rounded-xl border border-gray-200/80 dark:border-gray-700/60 bg-white dark:bg-navy-light p-4"
          >
            <p class="font-semibold text-gray-900 dark:text-white text-sm">{{ tc.name }}</p>
            <p v-if="tc.affiliation" class="text-xs text-gray-400 dark:text-gray-500 mt-0.5">{{ tc.affiliation }}</p>
            <p class="text-xs text-gray-500 dark:text-gray-400 mt-1">{{ tc.note }}</p>
          </div>
        </div>
      </AnimatedSection>
    </section>

    <!-- Contributing Organizations -->
    <section class="mb-20">
      <AnimatedSection>
        <div class="mb-8">
          <h2 class="text-2xl font-serif font-bold text-gray-900 dark:text-white">Contributing Organizations</h2>
        </div>
      </AnimatedSection>

      <div class="grid md:grid-cols-3 gap-5">
        <AnimatedSection v-for="(org, i) in organizations" :key="org.name" :style="{ transitionDelay: `${i * 80}ms` }">
          <BaseCard :href="org.url || undefined" :padding="'lg'" :hover="!!org.url">
            <h3 class="font-serif font-bold text-xl text-gray-900 dark:text-white mb-1">{{ org.name }}</h3>
            <p class="text-xs text-gray-400 dark:text-gray-500 mb-4">{{ org.full }}</p>
            <ul class="space-y-2">
              <li v-for="c in org.contributions" :key="c" class="text-sm text-gray-600 dark:text-gray-300 flex items-start gap-2">
                <span class="w-1.5 h-1.5 rounded-full bg-elf-salmon/60 dark:bg-elf-salmon/40 shrink-0 mt-1.5" />
                {{ c }}
              </li>
            </ul>
          </BaseCard>
        </AnimatedSection>
      </div>
    </section>

    <!-- Open Source -->
    <section class="mb-12">
      <AnimatedSection>
        <div class="pt-8 border-t border-gray-100 dark:border-gray-700/40">
          <h2 class="text-xl font-serif font-bold text-gray-900 dark:text-white mb-3">Open Source Maintenance</h2>
          <p class="text-sm text-gray-500 dark:text-gray-400 leading-relaxed">
            The AP 210 online resources, including this website, the research data archive, and educational materials,
            are maintained by the <a href="https://expresslang.org" target="_blank" rel="noopener" class="text-elf-blue dark:text-elf-blue hover:underline">EXPRESS Language Foundation</a>
            and the open source community at <a href="https://github.com/expresslang" target="_blank" rel="noopener" class="text-elf-blue dark:text-elf-blue hover:underline">GitHub</a>.
          </p>
          <p class="text-sm text-gray-400 dark:text-gray-500 mt-3">
            The research datasets are released under Creative Commons Attribution 4.0 International License (CC-BY 4.0) to support open science and reproducible research.
          </p>
        </div>
      </AnimatedSection>
    </section>
  </div>
</template>
