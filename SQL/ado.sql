CREATE TABLE tb_complexity (id SERIAL NOT NULL UNIQUE, ds_complexity VARCHAR, dt_insert TIMESTAMP DEFAULT NOW());

CREATE TABLE tb_algorithm (
    id SERIAL NOT NULL, 
    algorithm_name VARCHAR NOT NULL,
    algorithm_upper_name VARCHAR NOT NULL,
    ds_algorithm VARCHAR NOT NULL,
    bc_time INTEGER REFERENCES tb_complexity(id),
    mc_time INTEGER REFERENCES tb_complexity(id),
    wc_time INTEGER REFERENCES tb_complexity(id),
    ds_reference VARCHAR NOT NULL,
    dt_insert TIMESTAMP DEFAULT NOW()
);

SELECT tb_algorithm.algorithm_name as Algoritmo, 
    tb_algorithm.ds_algorithm as Aplicação, 
    (SELECT ds_complexity FROM tb_complexity WHERE id = tb_algorithm.bc_time) as Melhor_caso,
    (SELECT ds_complexity FROM tb_complexity WHERE id = tb_algorithm.mc_time) as Medio_caso,
    (SELECT ds_complexity FROM tb_complexity WHERE id = tb_algorithm.wc_time) as Pior_caso,
    tb_algorithm.ds_reference as Referencia,
    tb_algorithm.ds_obs as Observação
FROM tb_algorithm
INNER JOIN tb_complexity
ON tb_complexity.id = tb_algorithm.bc_time;


SELECT tb_algorithm.algorithm_name as Algoritmo, tb_algorithm.ds_algorithm as Aplicação, (SELECT ds_complexity FROM tb_complexity WHERE id = tb_algorithm.bc_time) as Melhor_caso, (SELECT ds_complexity FROM tb_complexity WHERE id = tb_algorithm.mc_time) as Medio_caso, (SELECT ds_complexity FROM tb_complexity WHERE id = tb_algorithm.wc_time) as Pior_caso, tb_algorithm.ds_reference as Referencia, tb_algorithm.ds_obs as Observação FROM tb_algorithm INNER JOIN tb_complexity ON tb_complexity.id = tb_algorithm.bc_time;