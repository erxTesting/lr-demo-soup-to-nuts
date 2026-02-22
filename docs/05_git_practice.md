# Git Practice (GitHub Upstream, Team Clones)

This repo is hosted on GitHub as the upstream (source of truth).
Our team normally uses Bitbucket at work; this is a safe practice repo.

Recommended workflow (best for learning):
1) Fork the repo into your own GitHub account
2) Clone your fork locally
3) Create a feature branch
4) Commit changes
5) Push to your fork
6) Open a Pull Request (PR)

Option A: Fork + PR (preferred)
- Pros: everyone practices PRs without stepping on each other
- Pros: upstream stays clean

Option B: Clone upstream read-only (ok for solo)
- Pros: simplest
- Cons: cannot push unless you have write access

Branch naming
- feature/<short-description>
- fix/<short-description>
- docs/<short-description>

Commit message style
- Add: <what you added>
- Fix: <what you fixed>
- Docs: <what you documented>
- Refactor: <what you reorganized>

PR checklist
- Script builds in VuGen
- Script CHANGELOG.md updated (scripts/.../CHANGELOG.md)
- No results committed (results are ignored)
- Transactions are stable (no dynamic data in names)
- Behavior change explained in PR description

Cheat sheet (commands)

Clone your fork:
  git clone <your-fork-url>
  cd lr-demo-soup-to-nuts

Add upstream remote:
  git remote add upstream <upstream-url>
  git remote -v

Create a branch:
  git checkout -b feature/add-search-action

Stage + commit:
  git add .
  git commit -m "Add: search business action and routing"

Push branch:
  git push -u origin feature/add-search-action

Sync your fork with upstream:
  git checkout main
  git fetch upstream
  git merge upstream/main
  git push origin main
