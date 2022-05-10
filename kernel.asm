[BITS 32]

[global start]
[extern jaya]

start:
  call jaya

  cli  
  hlt 
