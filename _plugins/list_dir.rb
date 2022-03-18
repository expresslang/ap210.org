# SPDX-FileCopyrightText: 2021 Michael Struwe <michaelstruwe@gmx.net>
# SPDX-License-Identifier: LGPL-3.0-or-later
#
# Adds a list_files tag to Liquid (the templating engine used by jekyll),
# i.e. defines what e.g. {% list_files blabla some/path/*.md %} does.  In this
# example, it will create a variable blabla in the context, i.e. define what
# e.g. {{ blabla }} does.  The variable is set to the list of Pages that were
# found.

module Jekyll
  class ListFiles < Liquid::Tag

    def initialize(tag_name, text, tokens)
      super

      args = text.strip.split(' ', 2)
      @variable_name = args[0]
      @path_glob = args[1]
    end

    def render(context)
      # This is a bug if you have multiple Jekyll sites
      site = Jekyll.sites.first
      source = site.source

      files = Dir.glob(@path_glob)
      context[@variable_name] = files
      # context[@variable_name] = files.map do |path|
      #   dirname = File.dirname(path)
      #   filename = File.basename(path)
      #   Page.new(site, source, dirname, filename)
      #   p "Created page", source, dirname, filename
      # end
      ""
    end
  end
end

Liquid::Template.register_tag('listfiles', Jekyll::ListFiles)
