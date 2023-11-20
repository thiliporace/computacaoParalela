## Projeto Final Computacao Paralela <br> <br>

**Fazendo o calculo para a Serie de Taylor com N = 500** <br> <br>

Tempo de execucao do codigo na versão serial: <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/9b775451-e6fa-4096-90fb-bbe06e8646d6) <br>

*A versão serial executou em 6.288s* <br> <br>

Tempo de execucao do codigo versão paralela (para 2 threads): <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/7775a8aa-cd07-4489-8076-9d1a0842b7f8) <br>

*A versão paralela (2 threads) executou em 3.012s* <br> <br>

Tempo de execucao do codigo versão paralela (para 4 threads): <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/1257de7a-c7aa-4b1e-aa77-f83cdcfbedcc)


*A versão paralela (4 threads) executou em 3.203s* <br> <br>

Calculando o Speedup que foi obtido entre a versão paralela (2 threads) e a versão serial para N = 500, usando Ts (tempo serial) / Tp (tempo paralelo) conseguimos <br>

Speedup = Ts/Tp = 6.288/3.012 = 2.0876494 <br><br>

Calculando o Speedup obtido entre a versão paralela com 4 threads e a versão paralela com 2 threads para N = 500, usando T2 / T4 conseguimos <br>

Speedup = T2/T4 = 3.012/3.203 = 0.9403684 <br><br><br>



**Fazendo o calculo para a Serie de Taylor com N = 10000** <br> <br>

Tempo de execucao do codigo na versão serial: <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/46a58c3c-77fd-43f0-92b1-acc118093d3e) <br>

*A versão serial executou em 391.803s* <br> <br>


Tempo de execucao do codigo versão paralela (para 2 threads): <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/694f0a09-e1dd-43fc-b367-bf72f05e7017) <br>

*A versão paralela (2 threads) executou em 47.465s* <br> <br>


Tempo de execucao do codigo versão paralela (para 4 threads): <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/092c3901-4305-45c1-a2f6-2e517482350b)


*A versão paralela (4 threads) executou em 56.904s* <br> <br>


Calculando o Speedup que foi obtido entre a versão paralela (2 threads) e a versão serial para N = 10000, usando Ts (tempo serial) / Tp (tempo paralelo) conseguimos <br>

Speedup = Ts/Tp =  391.803/47.465 = 8,25456652 <br><br>

Calculando o Speedup obtido entre a versão paralela com 4 threads e a versão paralela com 2 threads para N = 10000, usando T2 / T4 conseguimos <br>

Speedup = T2/T4 = 47.465/56.904 = 0,834124138 <br><br>

#Diagrama para N = 10000 iteracoes: <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/1b4b45ea-9f90-46a2-8e97-3d40388ad44e)

