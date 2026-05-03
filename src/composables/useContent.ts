export interface ContentData {
  title: string
  slug: string
  date: string | null
  categories: string[]
  authors: Array<{ name: string; email?: string; use_picture?: string }>
  excerpt: string
  toc: Array<{ id: string; title: string; level: number }>
  body: string
  frontmatter: Record<string, unknown>
}

const contentCache = new Map<string, ContentData>()

const pageModules = import.meta.glob<ContentData>('../content/pages/*.json', { eager: true })
const postModules = import.meta.glob<ContentData>('../content/posts/*.json', { eager: true })
const applicationModules = import.meta.glob<ContentData>('../content/application/*.json', { eager: true })
const standardsModules = import.meta.glob<ContentData>('../content/standards/*.json', { eager: true })
const researchModules = import.meta.glob<ContentData>('../content/research/*.json', { eager: true })
const foundationsModules = import.meta.glob<ContentData>('../content/foundations/*.json', { eager: true })
const ap210ConceptsModules = import.meta.glob<ContentData>('../content/ap210-concepts/*.json', { eager: true })
const readingDataModules = import.meta.glob<ContentData>('../content/reading-data/*.json', { eager: true })
const queryingDataModules = import.meta.glob<ContentData>('../content/querying-data/*.json', { eager: true })
const programmingModules = import.meta.glob<ContentData>('../content/programming/*.json', { eager: true })

const sectionModules: Record<string, Record<string, ContentData>> = {
  pages: pageModules,
  posts: postModules,
  application: applicationModules,
  standards: standardsModules,
  research: researchModules,
  foundations: foundationsModules,
  'ap210-concepts': ap210ConceptsModules,
  'reading-data': readingDataModules,
  'querying-data': queryingDataModules,
  programming: programmingModules,
}

function resolveKey(path: string): string {
  const parts = path.split('/')
  return parts[parts.length - 1].replace('.json', '')
}

export async function useContent(section: string, slug: string): Promise<ContentData | null> {
  const key = `${section}/${slug}`
  if (contentCache.has(key)) return contentCache.get(key)!

  const modules = sectionModules[section]
  if (!modules) return null

  for (const [path, data] of Object.entries(modules)) {
    if (resolveKey(path) === slug) {
      const content = (data as any).default || data
      contentCache.set(key, content)
      return content
    }
  }
  return null
}

export async function useContentList(section: string): Promise<ContentData[]> {
  const modules = sectionModules[section]
  if (!modules) return []

  const items = Object.values(modules).map((data) => (data as any).default || data)
  return items.sort((a, b) => {
    if (a.date && b.date) return b.date.localeCompare(a.date)
    return (a.title ?? '').localeCompare(b.title ?? '')
  })
}
