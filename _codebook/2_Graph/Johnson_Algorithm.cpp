h=Bellman¡VFord.dis
W_new(u,v)=W(u,v)+h(u)-h(v)

d=dijkstra

dis(s,t)=d(t)-h(s)+h(t)
