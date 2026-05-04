import { cpSync, mkdirSync, existsSync } from 'node:fs'
import { resolve } from 'node:path'

const ROOT = resolve(import.meta.dirname, '..')
const PUBLIC = resolve(ROOT, 'public')
const ASSETS = resolve(ROOT, 'assets/implementation_reference/NIST_AP210_Javadoc_Project/jsdai_queries')

const copies: Array<{ from: string; to: string }> = [
  { from: resolve(ASSETS, 'ap210_jsdai_query_doc'), to: resolve(PUBLIC, 'resources/javadoc') },
  { from: resolve(ASSETS, 'armIndex.htm'), to: resolve(PUBLIC, 'resources/arm-mim-reference/armIndex.htm') },
  { from: resolve(ASSETS, 'mimIndex.htm'), to: resolve(PUBLIC, 'resources/arm-mim-reference/mimIndex.htm') },
  { from: resolve(ASSETS, 'wg3n2602_10303_210_ed2_IS'), to: resolve(PUBLIC, 'resources/arm-mim-reference/wg3n2602_10303_210_ed2_IS') },
]

for (const { from, to } of copies) {
  if (!existsSync(from)) {
    console.warn(`  ⚠ Source not found: ${from}`)
    continue
  }
  mkdirSync(resolve(to, '..'), { recursive: true })
  cpSync(from, to, { recursive: true })
  console.log(`  ✓ ${resolve(to, '..').replace(ROOT + '/', '')}/`)
}
