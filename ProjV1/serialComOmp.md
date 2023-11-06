Criamos um novo codigo usando a biblioteca OMP.H, para oferecer maior precisao na hora de fazer o calculo do numero decimal do E e na hora de printar esse valor.<br>

Tambem criamos uma funcao para criar um arquivo com o valor do E, pois como previamente estavamos usando Double para registrar o valor, ele eventualmente atingia o limite de 10^308 caracteres, o que limitou nosso N, que atingiu valor maximo de 171.<br><br>

Ao usar o numero de E armazenado em um arquivo .txt, conseguimos aumentar o tamanho do N para 50.000, aumentando (e muito) o tamanho do N que o codigo pode ser capaz de rodar.<br><br><br>
