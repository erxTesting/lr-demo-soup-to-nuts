# Demoblaze Modular Workload Script

Script name: Demoblaze_Modular_Workload
Protocol: Web (HTTP/HTML)
Target: https://api.demoblaze.com

Design goals:
- Demonstrate modularization (business_actions.c)
- Demonstrate workload modeling (workload.c)
- Demonstrate controlled randomness (util_random.c)
- Teach best practices: transactions, naming, version stamping, changelog discipline

How to run:
1) Open this folder in VuGen
2) Build and replay
3) Start with 1 Vuser, 1 iteration

Key files:
- src/workload.c: workload model / routing
- src/business_actions.c: business actions
- src/util_random.c: randomness helpers
- src/workload.h: configuration + version metadata
