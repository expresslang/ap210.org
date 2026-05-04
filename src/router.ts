import type { RouteRecordRaw } from 'vue-router'

const SectionPage = () => import('@/components/content/SectionPage.vue')
const SimplePage = () => import('@/components/content/SimplePage.vue')

export const routes: RouteRecordRaw[] = [
  // Custom pages
  {
    path: '/',
    component: () => import('@/pages/index.vue'),
    meta: { title: '', description: 'ISO 10303-210 — Electronic Assembly, Interconnect and Packaging Design. Education, research, and resources.' },
  },
  {
    path: '/learn',
    component: () => import('@/pages/learn/index.vue'),
    meta: { title: 'Learn', description: 'Structured courses for AP210 — from STEP foundations to programming with AP210 data.' },
  },
  {
    path: '/blog',
    component: () => import('@/pages/blog/index.vue'),
    meta: { title: 'Blog', description: 'News and updates about AP210.' },
  },
  {
    path: '/blog/:slug',
    component: () => import('@/pages/blog/[slug].vue'),
    meta: { title: 'Blog' },
  },

  // About section
  { path: '/about', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'about', navKey: 'about', basePath: '/about', title: 'About', description: 'About ISO 10303-210 (AP 210) — the STEP application protocol for electronic assembly and interconnect design data exchange.' } },
  { path: '/about/scope', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'about-scope', navKey: 'about', basePath: '/about', title: 'Scope', description: 'Scope of AP 210 — what the standard covers including product definition, physical design, connectivity, and design rules.' } },
  { path: '/about/domain', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'about-domain', navKey: 'about', basePath: '/about', title: 'Domain', description: 'The AP 210 domain of electronic assembly, interconnect, and packaging design — from components through complete assemblies.' } },
  { path: '/about/team', component: () => import('@/pages/about/team.vue'), meta: { navKey: 'about', basePath: '/about', title: 'Team', description: 'People and organizations behind AP 210 — NIST, PDES Inc., ISO TC 184/SC 4, and key contributors.' } },

  // Standards section
  { path: '/standard', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'standard', navKey: 'standards', basePath: '/standard', title: 'Standards', description: 'Editions of ISO 10303-210 — four editions spanning two decades of electronic design data standardization.' } },
  { path: '/standard/:slug', component: SectionPage, meta: { contentSection: 'standards', navKey: 'standards', basePath: '/standard', title: 'Standard', description: 'Edition of ISO 10303-210 — the AP210 standard for electronic assembly, interconnect, and packaging design.' } },

  // Application section
  { path: '/application', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'application', navKey: 'application', basePath: '/application', title: 'Application', description: 'Application documentation for AP210 — concepts, recommended practices, terminology, and examples.' } },
  { path: '/application/:slug', component: SectionPage, meta: { contentSection: 'application', navKey: 'application', basePath: '/application', title: 'Application', description: 'Application documentation for AP210 electronic assembly design.' } },

  // Research section
  { path: '/research', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'research', navKey: 'research', basePath: '/research', title: 'Research', description: 'Collaborative research projects from NIST and PDES Inc. advancing AP210 tooling and methodology.' } },
  { path: '/research/:slug', component: SectionPage, meta: { contentSection: 'research', navKey: 'research', basePath: '/research', title: 'Research', description: 'AP210 research project — NIST and PDES Inc. collaborative research on electronic design data.' } },

  // Learn modules
  { path: '/learn/foundations', component: SectionPage, meta: { contentSection: 'foundations', contentSlug: 'index', navKey: 'foundations', basePath: '/learn/foundations', showLessonNav: true, title: 'STEP & EXPRESS Foundations', description: 'Module 1: Introduction to the STEP standard, EXPRESS modeling language, and business context for AP210.' } },
  { path: '/learn/foundations/:slug', component: SectionPage, meta: { contentSection: 'foundations', navKey: 'foundations', basePath: '/learn/foundations', showLessonNav: true, title: 'Foundations', description: 'STEP and EXPRESS foundations — core concepts for understanding AP210.' } },
  { path: '/learn/ap210-concepts', component: SectionPage, meta: { contentSection: 'ap210-concepts', contentSlug: 'index', navKey: 'ap210-concepts', basePath: '/learn/ap210-concepts', showLessonNav: true, title: 'AP210 Concepts', description: 'Module 2: Core AP210 concepts including product structure, connectivity, physical design, and design rules.' } },
  { path: '/learn/ap210-concepts/:slug', component: SectionPage, meta: { contentSection: 'ap210-concepts', navKey: 'ap210-concepts', basePath: '/learn/ap210-concepts', showLessonNav: true, title: 'AP210 Concepts', description: 'AP210 concepts — understanding the electronic assembly information model.' } },
  { path: '/learn/reading-data', component: SectionPage, meta: { contentSection: 'reading-data', contentSlug: 'index', navKey: 'reading-data', basePath: '/learn/reading-data', showLessonNav: true, title: 'Reading AP210 Data', description: 'Module 3: Walk-throughs of AP210 STEP files from simple examples to complex multi-layer assemblies.' } },
  { path: '/learn/reading-data/:slug', component: SectionPage, meta: { contentSection: 'reading-data', navKey: 'reading-data', basePath: '/learn/reading-data', showLessonNav: true, title: 'Reading Data', description: 'Reading AP210 data files — understanding STEP Part 21 structure and content.' } },
  { path: '/learn/querying-data', component: SectionPage, meta: { contentSection: 'querying-data', contentSlug: 'index', navKey: 'querying-data', basePath: '/learn/querying-data', showLessonNav: true, title: 'Querying AP210 Data', description: 'Module 4: Using EXPRESS queries to extract information from AP210 datasets.' } },
  { path: '/learn/querying-data/:slug', component: SectionPage, meta: { contentSection: 'querying-data', navKey: 'querying-data', basePath: '/learn/querying-data', showLessonNav: true, title: 'Querying Data', description: 'Querying AP210 data — EXPRESS query patterns for data extraction.' } },
  { path: '/learn/programming', component: SectionPage, meta: { contentSection: 'programming', contentSlug: 'index', navKey: 'programming', basePath: '/learn/programming', showLessonNav: true, title: 'Programming with AP210', description: 'Module 5: Building applications with the JSDAI Java framework to work with AP210 data.' } },
  { path: '/learn/programming/:slug', component: SectionPage, meta: { contentSection: 'programming', navKey: 'programming', basePath: '/learn/programming', showLessonNav: true, title: 'Programming', description: 'Programming with AP210 — JSDAI Java API for AP210 data access.' } },

  // Resources section
  { path: '/resources', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'resources', navKey: 'resources', basePath: '/resources', title: 'Resources', description: 'Reference materials for AP210 — test cases, Javadoc API, EXPRESS schema, and implementation tools.' } },
  { path: '/resources/test-cases', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'resources-test-cases', navKey: 'resources', basePath: '/resources', title: 'Test Cases', description: '35 validated test cases from the PDES Test Cases Project covering the full range of AP210 entities.' } },
  { path: '/resources/javadoc', beforeEnter: (_to, _from, next) => { window.location.href = '/resources/javadoc/index.html' }, meta: { title: 'Java API', description: 'Complete Javadoc for the NIST AP210 JSDAI reference implementation.' } },
  { path: '/resources/arm-mim-reference', beforeEnter: (_to, _from, next) => { window.location.href = '/resources/arm-mim-reference/armIndex.htm' }, meta: { title: 'ARM/MIM Reference', description: 'Cross-reference index of AP210 ARM and MIM entities.' } },
  { path: '/resources/implementation', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'resources-implementation', navKey: 'resources', basePath: '/resources', title: 'Implementation', description: 'Java source code from the NIST AP210 JSDAI reference implementation — MIMqueries, model traversal, and parameter extraction.' } },
  { path: '/resources/express-schema', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'resources-express-schema', navKey: 'resources', basePath: '/resources', title: 'EXPRESS Schema', description: 'The complete AP210 ARM extended longform EXPRESS schema — the authoritative information model definition.' } },
  { path: '/resources/discussions', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'resources-discussions', navKey: 'resources', basePath: '/resources', title: 'Discussions', description: 'Primary source materials from the PDES AP210 Rules Model design process.' } },
  { path: '/resources/training-materials', component: SectionPage, meta: { contentSection: 'pages', contentSlug: 'resources-training-materials', navKey: 'resources', basePath: '/resources', title: 'Training Materials', description: 'Original PDES AP210 Training CD presentation slides from the July 2003 training program.' } },

  // Legal
  { path: '/privacy', component: SimplePage, meta: { contentSlug: 'privacy', title: 'Privacy Policy', description: 'Privacy policy for ap210.org — operated by the EXPRESS Language Foundation.' } },
  { path: '/tos', component: SimplePage, meta: { contentSlug: 'tos', title: 'Terms of Service', description: 'Terms of service for ap210.org — operated by the EXPRESS Language Foundation.' } },

  // 404
  { path: '/:pathMatch(.*)*', name: 'not-found', component: () => import('@/pages/404.vue'), meta: { title: 'Page Not Found' } },
]
