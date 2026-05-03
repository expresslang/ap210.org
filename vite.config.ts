import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'
import { resolve } from 'node:path'
import { globby } from 'globby'
import { basename } from 'node:path'

export default defineConfig({
  plugins: [vue()],
  resolve: {
    alias: {
      '@': resolve(__dirname, 'src'),
    },
  },
  ssgOptions: {
    script: 'async',
    formatting: 'minify',
    includedRoutes: async () => {
      const pages = await globby('src/content/pages/*.json')
      const posts = await globby('src/content/posts/*.json')
      const application = await globby('src/content/application/*.json')
      const standards = await globby('src/content/standards/*.json')
      const research = await globby('src/content/research/*.json')
      const foundations = await globby('src/content/foundations/*.json')
      const ap210Concepts = await globby('src/content/ap210-concepts/*.json')
      const readingData = await globby('src/content/reading-data/*.json')
      const queryingData = await globby('src/content/querying-data/*.json')
      const programming = await globby('src/content/programming/*.json')

      return [
        '/',
        '/about', '/about/scope', '/about/domain', '/about/team',
        '/standard', ...standards.map((p) => `/standard/${basename(p, '.json')}`),
        '/application', ...application.map((p) => `/application/${basename(p, '.json')}`),
        '/research', ...research.map((p) => `/research/${basename(p, '.json')}`),
        '/learn',
        '/learn/foundations', ...foundations.map((p) => `/learn/foundations/${basename(p, '.json')}`),
        '/learn/ap210-concepts', ...ap210Concepts.map((p) => `/learn/ap210-concepts/${basename(p, '.json')}`),
        '/learn/reading-data', ...readingData.map((p) => `/learn/reading-data/${basename(p, '.json')}`),
        '/learn/querying-data', ...queryingData.map((p) => `/learn/querying-data/${basename(p, '.json')}`),
        '/learn/programming', ...programming.map((p) => `/learn/programming/${basename(p, '.json')}`),
        '/resources', '/resources/test-cases', '/resources/javadoc', '/resources/arm-mim-reference',
        '/resources/implementation', '/resources/express-schema', '/resources/discussions',
        '/resources/training-materials',
        '/blog', ...posts.map((p) => `/blog/${basename(p, '.json')}`),
        '/privacy', '/tos', '/404',
      ]
    },
  },
})
