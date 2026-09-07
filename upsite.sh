#!/bin/sh
# Publish: commit the source and push. GitHub Actions builds Hugo and
# deploys to Pages (see .github/workflows/hugo.yml).
set -e
git pull --rebase
git add --all
git commit -m "${1:-up site}"
git push
