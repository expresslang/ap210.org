import type { RouteRecordRaw } from 'vue-router'

export const routes: RouteRecordRaw[] = [
  {
    path: '/',
    component: () => import('@/pages/index.vue'),
    meta: { title: '', description: 'ISO 10303-210 — Electronic Assembly, Interconnect and Packaging Design. Education, research, and resources.' },
  },
  {
    path: '/about',
    component: () => import('@/pages/about.vue'),
    meta: { title: 'About', description: 'About ISO 10303-210 (AP 210) — the STEP application protocol for electronic design data exchange.' },
  },
  {
    path: '/about/scope',
    component: () => import('@/pages/about-scope.vue'),
    meta: { title: 'Scope' },
  },
  {
    path: '/about/domain',
    component: () => import('@/pages/about-domain.vue'),
    meta: { title: 'Domain' },
  },
  {
    path: '/about/team',
    component: () => import('@/pages/about-team.vue'),
    meta: { title: 'Team' },
  },
  {
    path: '/standard',
    component: () => import('@/pages/standard/index.vue'),
    meta: { title: 'Standards', description: 'Editions of ISO 10303-210 — the AP210 standard for electronic assembly design.' },
  },
  {
    path: '/standard/:slug',
    component: () => import('@/pages/standard/[slug].vue'),
    meta: { title: 'Standard' },
  },
  {
    path: '/application',
    component: () => import('@/pages/application/index.vue'),
    meta: { title: 'Application', description: 'Application documentation for AP210 — concepts, recommended practices, and terminology.' },
  },
  {
    path: '/application/:slug',
    component: () => import('@/pages/application/[slug].vue'),
    meta: { title: 'Application' },
  },
  {
    path: '/research',
    component: () => import('@/pages/research/index.vue'),
    meta: { title: 'Research', description: 'Research projects and datasets for AP210 — NIST and PDES Inc. collaborative research.' },
  },
  {
    path: '/research/:slug',
    component: () => import('@/pages/research/[slug].vue'),
    meta: { title: 'Research' },
  },
  {
    path: '/learn',
    component: () => import('@/pages/learn/index.vue'),
    meta: { title: 'Learn', description: 'Structured courses for AP210 — from STEP foundations to programming with AP210 data.' },
  },
  {
    path: '/learn/foundations',
    component: () => import('@/pages/learn/foundations/index.vue'),
    meta: { title: 'STEP & EXPRESS Foundations' },
  },
  {
    path: '/learn/foundations/:slug',
    component: () => import('@/pages/learn/foundations/[slug].vue'),
    meta: { title: 'Foundations' },
  },
  {
    path: '/learn/ap210-concepts',
    component: () => import('@/pages/learn/ap210-concepts/index.vue'),
    meta: { title: 'AP210 Concepts' },
  },
  {
    path: '/learn/ap210-concepts/:slug',
    component: () => import('@/pages/learn/ap210-concepts/[slug].vue'),
    meta: { title: 'AP210 Concepts' },
  },
  {
    path: '/learn/reading-data',
    component: () => import('@/pages/learn/reading-data/index.vue'),
    meta: { title: 'Reading AP210 Data' },
  },
  {
    path: '/learn/reading-data/:slug',
    component: () => import('@/pages/learn/reading-data/[slug].vue'),
    meta: { title: 'Reading Data' },
  },
  {
    path: '/learn/querying-data',
    component: () => import('@/pages/learn/querying-data/index.vue'),
    meta: { title: 'Querying AP210 Data' },
  },
  {
    path: '/learn/querying-data/:slug',
    component: () => import('@/pages/learn/querying-data/[slug].vue'),
    meta: { title: 'Querying Data' },
  },
  {
    path: '/learn/programming',
    component: () => import('@/pages/learn/programming/index.vue'),
    meta: { title: 'Programming with AP210' },
  },
  {
    path: '/learn/programming/:slug',
    component: () => import('@/pages/learn/programming/[slug].vue'),
    meta: { title: 'Programming' },
  },
  {
    path: '/resources',
    component: () => import('@/pages/resources/index.vue'),
    meta: { title: 'Resources', description: 'Reference materials for AP210 — test cases, Javadoc, source code, and original training materials.' },
  },
  {
    path: '/resources/test-cases',
    component: () => import('@/pages/resources-test-cases.vue'),
    meta: { title: 'Test Cases' },
  },
  {
    path: '/resources/javadoc',
    beforeEnter: (_to, _from, next) => { window.location.href = '/resources/javadoc/index.html' },
    meta: { title: 'Java API' },
  },
  {
    path: '/resources/arm-mim-reference',
    beforeEnter: (_to, _from, next) => { window.location.href = '/resources/arm-mim-reference/armIndex.htm' },
    meta: { title: 'ARM/MIM Reference' },
  },
  {
    path: '/resources/implementation',
    component: () => import('@/pages/resources-implementation.vue'),
    meta: { title: 'Implementation' },
  },
  {
    path: '/resources/express-schema',
    component: () => import('@/pages/resources-express-schema.vue'),
    meta: { title: 'EXPRESS Schema' },
  },
  {
    path: '/resources/discussions',
    component: () => import('@/pages/resources-discussions.vue'),
    meta: { title: 'Discussions' },
  },
  {
    path: '/resources/training-materials',
    component: () => import('@/pages/resources-training-materials.vue'),
    meta: { title: 'Training Materials' },
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
  {
    path: '/privacy',
    component: () => import('@/pages/privacy.vue'),
    meta: { title: 'Privacy Policy' },
  },
  {
    path: '/tos',
    component: () => import('@/pages/tos.vue'),
    meta: { title: 'Terms of Service' },
  },
  {
    path: '/:pathMatch(.*)*',
    name: 'not-found',
    component: () => import('@/pages/404.vue'),
    meta: { title: 'Page Not Found' },
  },
]
