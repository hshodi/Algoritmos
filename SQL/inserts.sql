INSERT INTO tb_complexity (ds_complexity) VALUES ('n log n');

INSERT INTO tb_complexity (ds_complexity) VALUES ('log n');

INSERT INTO tb_complexity (ds_complexity) VALUES ('n²');

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference) 
    VALUES ('QuickSort', 'QUICKSORT', 'Ordenação de Vetores', 1, 1, 3, 'http://homepages.dcc.ufmg.br/~cunha/teaching/20121/aeds2/quicksort.pdf');

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference) 
    VALUES ('MergeSort', 'MERGESORT', 'Ordenação de Vetores', 1, 1, 1, 'http://quiz.geeksforgeeks.org/merge-sort/');

INSERT INTO tb_complexity (ds_complexity) VALUES ('n');

INSERT INTO tb_complexity (ds_complexity) VALUES ('1');

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference) 
    VALUES ('BuscaLinear', 'BUSCALINEAR', 'Busca em Vetor', (SELECT id FROM tb_complexity WHERE ds_complexity = '1'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n'), 'http://www.geeksforgeeks.org/analysis-of-algorithms-set-2-asymptotic-analysis/');

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference) 
    VALUES ('BubbleSort', 'BUBBLESORT', 'Ordenação de Vetor', (SELECT id FROM tb_complexity WHERE ds_complexity = 'n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n²'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n²'), 'http://bigocheatsheet.com/');

INSERT INTO tb_complexity (ds_complexity) VALUES ('nk');

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference) 
    VALUES ('RadixSort', 'RADIXSORT', 'Ordenação de Vetor', (SELECT id FROM tb_complexity WHERE ds_complexity = 'nk'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'nk'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'nk'), 'http://www.geeksforgeeks.org/radix-sort/');

ALTER TABLE tb_algorithm ADD COLUMN ds_obs VARCHAR DEFAULT NULL;

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference, ds_obs) 
    VALUES ('HashTable', 'HASHTABLE', 'Estrutura de Dado', (SELECT id FROM tb_complexity WHERE ds_complexity = '1'), (SELECT id FROM tb_complexity WHERE ds_complexity = '1'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n'), 'https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/', 'Estrutura de dado que associa chaves de pesquisa a valores. Seu objetivo é fazer uma busca rápida.');

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference, ds_obs) 
    VALUES ('Red-Black Trees', 'RED-BLACK TREES', 'Estrutura de Dado', (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), 'https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html', 'Árvore de busca binária com um atributo a mais para cada nó, a cor, que são preto e vermelho.') RETURNING (select count(*) from tb_algorithm);

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference) 
    VALUES ('TimSort', 'TIMSORT', 'Ordenação de Vetor', (SELECT id FROM tb_complexity WHERE ds_complexity = 'n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n log n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'n log n'), 'https://en.wikipedia.org/wiki/Timsort') RETURNING (select count(*) from tb_algorithm);


INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference, ds_obs) 
    VALUES ('KD Tree', 'KD TREE', 'Estrutura de Dado', (SELECT id FROM tb_complexity WHERE ds_complexity = 'n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), 'http://pointclouds.org/documentation/tutorials/kdtree_search.php', 'Organiza ponto num espaco de dimensão K.') RETURNING (select count(*) from tb_algorithm);

INSERT INTO tb_algorithm (algorithm_name, algorithm_upper_name, ds_algorithm, bc_time, mc_time, wc_time, ds_reference, ds_obs) 
    VALUES ('AVL Tree', 'AVL TREE', 'Estrutura de Dado', (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), (SELECT id FROM tb_complexity WHERE ds_complexity = 'log n'), 'https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm', 'Árvore que se auto balancea, evitando assim, um tempo maior de busca em um lado da árvore') RETURNING (select count(*) from tb_algorithm);