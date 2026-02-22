# LoadRunner Demo: Soup to Nuts (Modular + Randomized Workload)

Purpose:
- Teach how to structure a LoadRunner Web (HTTP/HTML) C script like real software
- Demonstrate workload modeling (weighted random actions, session steps, pacing)
- Provide a safe place to practice Git (branching, commits, PRs, review)

Target system:
- https://api.demoblaze.com (demo-friendly)

Repo layout:
- scripts/ : LoadRunner script(s)
- docs/ : walkthroughs (VuGen, Controller, Analysis, Git practice)
- exercises/ : step-by-step practice tasks

Quick start:
1) Clone repo
2) Open: scripts/demoblaze_modular_workload/ in VuGen
3) Run 1 Vuser, 1 iteration
4) Complete exercises in order

Rules:
- Don’t commit VuGen results or large binaries (see .gitignore)
- Any code change must update the script CHANGELOG:
  scripts/demoblaze_modular_workload/CHANGELOG.md
- Keep transaction names stable across versions (no dynamic values)

Suggested learning path:
- docs/01_setup.md
- docs/02_vugen_walkthrough.md
- exercises/01_add_new_business_action/README.md
- docs/05_git_practice.md
- docs/03_controller_walkthrough.md
- docs/04_analysis_walkthrough.md
