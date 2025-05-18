---
title: Research
layout: docs
permalink: /application/research/
has_children: true
---

## Research datasets

Below is every dataset currently published on this site.
Select the title for full details, or choose **Download** to grab the data package directly.

{% comment %}
A-Z sorted bulleted list of every page that lives in the `_research` collection.
As soon as you drop a new file into `_research/`, it appears here automatically—no manual edits.
{% endcomment %}

{% assign items = site.research | sort: "title" %}
{% for item in items %}
* <a href="{{ item.url | relative_url }}">{{ item.title }}</a> – <em>{{ item.summary }}</em>
{% endfor %}
