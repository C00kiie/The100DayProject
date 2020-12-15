<h1> project-003: Recursive links scraper </h1>

As simple as it sounds, you can scrape as many links as you wish, just simply specify the initial URL and the specified depth and you'll have yourself a nice list of links

<h4> Usage </h4>

```bash
./main.py http://www.google.com --depth 1
[*] http://schema.org/WebPage
[*] http://webschemas.org/
[*] https://docs.google.com/a/google.com/forms/d/1krxHlWJAO3JgvHRZV9Rugkr9VYnMdrI10xbGsWt733c/viewform?entry.1174568178&entry.41124795=http://schema.org/WebPage&entry.882602760=Type
[*] http://www.w3.org/wiki/WebSchemas/Accessibility
[*] http://www.iana.org/assignments/media-types/media-types.xhtml
[*] http://tools.ietf.org/html/bcp47
[*] http://schema.org/version/2.0/
[*] http://creativecommons.org/licenses/by-nc-sa/3.0/us/deed.en_US&#34;&gt;&lt;img
[*] http://creativecommons.org/licenses/by-nc-sa/3.0/us/deed.en_US&#34
[*] http://www.w3.org/1999/02/22-rdf-syntax-ns#
[*] http://www.w3.org/2000/01/rdf-schema#
[*] http://schema.org/
[*] http://www.w3.org/2001/XMLSchema#
[*] http://example.com/great-multiplication-intro.html
[*] http://pending.schema.org
[*] http://bib.schema.org
[*] http://www.w3.org/wiki/WebSchemas/SchemaDotOrgSources#source_rNews
[*] http://www.w3.org/wiki/WebSchemas/SchemaDotOrgSources#source_bibex
[*] http://www.w3.org/2002/07/owl#equivalentProperty
[*] http://purl.org/dc/terms/description
<More Links Here>
```

It was a bit tedious to do this (as I did it many times before) but I thought it's finally the time to make myself learn doing the argument parsing properly.
