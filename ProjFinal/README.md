## Projeto Final Computacao Paralela <br> <br>


### Tutorial para rodar o codigo e executar na linguagem C: <br> <br>

1. Abrir uma instancia EC2 dentro da AWS de tamanho *medium* ou *large*, de preferencia com as maquinas especificas **t2.medium** ou **z1d.large** <br>
2. Se conecte a instancia criada <br> 
3. Instalar o GCC usando o comando *sudo dnf install gcc* <br> 
4. Instalar a biblioteca GMP por meio do comando *sudo dnf install gmp-devel* <br> 
5. Abrir o vi e colocar o codigo usando *vi file.c* (sem as aspas) <br>
6. Compilar o codigo escrito em C por meio do comando *gcc file.c -o file -fopenmp -lm -lgmp* <br>
7. Para calcular o tempo, usar o comando *time ./file*
 <br><br><br><br><br>




### Fazendo o calculo para a Serie de Taylor com N = 500 <br> <br>

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

Speedup = T2/T4 = 3.012/3.203 = 0.9403684 <br><br><br><br>



### Fazendo o calculo para a Serie de Taylor com N = 10000 <br> <br>

Tempo de execucao do codigo na versão serial: <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/46a58c3c-77fd-43f0-92b1-acc118093d3e) <br>

*A versão serial executou em 391.803s* <br>
*Obs: Neste caso o serial demorou muito tempo para rodar por conta da alocação de bits da função mpf_init2(), que quanto mais bits você aloca para as variáveis em questão, mais lento fica o programa. Como nós alocamos 67 milhões de bits para a versão paralela, também tivemos que alocar essa mesma quantidade de bits para a versão serial também, por isso essa enorme diferença de tempo.*
<br> <br>


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

## Valor de E <br>

O valor de E obtido está localizado no arquivo "ValorParalelo.txt", aqui está uma prévia desse valor: <br>
2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274 <br>
Comparando ambos os arquivos com os valores de E, obtivemos a seguinte quantidade casas de precisão: <br>
![image](https://github.com/thiliporace/computacaoParalela/assets/93730460/ca76c9a9-008e-427f-babd-69cf59c0e065) <br> 
Utilizamos o seguinte código para a comparação de arquivos: <br>
![image](https://github.com/thiliporace/computacaoParalela/assets/93730460/9d0d8fb5-e79e-4591-903e-5ca21ae7ec8d) <br> <br>


## Diagrama de decomposição de tarefas para N = 1000 iterações: <br>

![image](https://github.com/thiliporace/computacaoParalela/assets/85422792/1b4b45ea-9f90-46a2-8e97-3d40388ad44e)

