export interface NavItem {
  title: string
  slug?: string
  path?: string
  children?: NavItem[]
}

export const aboutNavigation: NavItem[] = [
  { title: 'About AP 210', path: '/about' },
  { title: 'Scope', path: '/about/scope' },
  { title: 'Domain', path: '/about/domain' },
  { title: 'Team', path: '/about/team' },
]

export const mainNavigation: NavItem[] = [
  { title: 'Application', path: '/application' },
  { title: 'Research', path: '/research' },
  { title: 'Standards', path: '/standard' },
  { title: 'Learn', path: '/learn' },
  { title: 'Resources', path: '/resources' },
  {
    title: 'About',
    path: '/about',
    children: [
      { title: 'About AP 210', path: '/about' },
      { title: 'Scope', path: '/about/scope' },
      { title: 'Domain', path: '/about/domain' },
      { title: 'Team', path: '/about/team' },
    ],
  },
  { title: 'Blog', path: '/blog' },
]

export const applicationNavigation: NavItem[] = [
  { title: 'Overview', slug: 'index' },
  { title: 'Concept of Operations', slug: 'concepts' },
  { title: 'Recommended Practices', slug: 'recommended-practices' },
  { title: 'Terms & Glossary', slug: 'terms' },
  { title: 'Examples', slug: 'examples' },
]

export const standardsNavigation: NavItem[] = [
  { title: 'Overview', slug: 'index' },
  { title: 'Edition 1', slug: 'ed1' },
  { title: 'Edition 2', slug: 'ed2' },
  { title: 'Edition 3', slug: 'ed3' },
  { title: 'Edition 4', slug: 'ed4' },
]

export const researchNavigation: NavItem[] = [
  { title: 'Overview', slug: 'index' },
  {
    title: 'NIST Projects',
    children: [
      { title: 'CFD Analysis', slug: 'nist-cfd' },
      { title: 'GDT for Connectors', slug: 'nist-gdt-connectors' },
      { title: 'GDT for Packages', slug: 'nist-gdt-packages' },
      { title: 'SPICE Integration', slug: 'nist-spice' },
    ],
  },
  {
    title: 'PDES Inc. Projects',
    children: [
      { title: 'AP210 Viewer', slug: 'pdes-viewer' },
      { title: 'IDF to AP210', slug: 'pdes-idf2ap210' },
      { title: 'Data Archive', slug: 'data-archive' },
    ],
  },
]

export const foundationsNavigation: NavItem[] = [
  { title: 'Module Overview', slug: 'index' },
  { title: 'Introduction to STEP', slug: 'step-overview' },
  { title: 'The EXPRESS Language', slug: 'express-intro' },
  { title: 'Constrained Objects', slug: 'constrained-objects' },
  { title: 'Information Modeling Summary', slug: 'info-modeling' },
  { title: 'STEP and PDES Inc.', slug: 'step-pdes' },
  { title: 'STEP Application Protocols', slug: 'application-protocols' },
  { title: 'Engineering Frameworks', slug: 'engineering-frameworks' },
  { title: 'Business Context', slug: 'business-context' },
]

export const ap210ConceptsNavigation: NavItem[] = [
  { title: 'Module Overview', slug: 'index' },
  { title: 'AP210 Overview and Scope', slug: 'overview' },
  { title: 'Product Classification', slug: 'product-classification' },
  { title: 'Product Structure', slug: 'product-structure' },
  { title: 'Functional Decomposition', slug: 'functional-decomposition' },
  { title: 'Physical Design', slug: 'physical-design' },
  { title: 'Connectivity Modeling', slug: 'connectivity' },
  { title: 'Requirements Capture', slug: 'requirements' },
  { title: 'Library Definitions', slug: 'library-definitions' },
  { title: 'Design Definitions', slug: 'design-definitions' },
  { title: 'Design Rules', slug: 'design-rules' },
  { title: 'Design-Usage Mapping', slug: 'design-usage-mapping' },
]

export const readingDataNavigation: NavItem[] = [
  { title: 'Module Overview', slug: 'index' },
  { title: 'STEP File Anatomy', slug: 'step-file-anatomy' },
  { title: 'Resistance Module', slug: 'resistance-module' },
  { title: 'Wheatstone Bridge', slug: 'wheatstone-bridge' },
  { title: 'Component Placement', slug: 'component-placement' },
  { title: 'Physical Requirements', slug: 'physical-requirements' },
  { title: 'Layer Stack Modeling', slug: 'layer-stack' },
  { title: 'Complete Design', slug: 'complete-design' },
  { title: 'Complex Multi-layer PCA', slug: 'complex-pca' },
]

export const queryingDataNavigation: NavItem[] = [
  { title: 'Module Overview', slug: 'index' },
  { title: 'Query Concepts', slug: 'query-concepts' },
  { title: 'Product Category Queries', slug: 'product-category-queries' },
  { title: 'Component Location Queries', slug: 'component-location-queries' },
  { title: 'Interconnect Queries', slug: 'interconnect-queries' },
  { title: 'Parameter Queries', slug: 'parameter-queries' },
  { title: 'Material Queries', slug: 'material-queries' },
]

export const programmingNavigation: NavItem[] = [
  { title: 'Module Overview', slug: 'index' },
  { title: 'JSDAI Introduction', slug: 'jsdai-intro' },
  { title: 'Model Traversal', slug: 'model-traversal' },
  { title: 'MIMqueries Interface', slug: 'mimqueries' },
  { title: 'Location and Shape', slug: 'location-shape' },
  { title: 'Stratum and Layers', slug: 'stratum-layer' },
  { title: 'PCA and PCB', slug: 'pca-pcb' },
  { title: 'Parameters', slug: 'parameters' },
  { title: 'Custom Applications', slug: 'custom-applications' },
]
