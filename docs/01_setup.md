# Setup

Goal: get to a successful VuGen replay and a clean Git workflow.

Prereqs:
- LoadRunner / VuGen installed (team standard version)
- Git installed
- A GitHub account (recommended for fork + PR workflow)

Steps:
1) Clone or fork the repo
2) Open the script folder in VuGen:
   scripts/demoblaze_modular_workload/
3) Build and replay with 1 Vuser, 1 iteration
4) If replay fails:
   - Check internet access to https://api.demoblaze.com
   - Ensure protocol is Web (HTTP/HTML)
   - Ensure the script compiles (Build)
