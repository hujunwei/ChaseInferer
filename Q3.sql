--a--
SELECT bar FROM frequents WHERE drinker = 'Dan';
--b--
SELECT name,address FROM frequents,drinker WHERE (frequents.drinker = drinker.name AND bar = 'Satisfaction' AND times_a_week > 1);
--c--
SELECT DISTINCT bar FROM serves, likes WHERE likes.drinker = 'Eve' AND serves.price <= 2.75;
--d--
(SELECT drinker FROM likes WHERE beer = 'Amstel') EXCEPT (SELECT drinker FROM likes WHERE beer = 'Corona');
--e--
-- ONLY SELECT OUT THE MIN PRICE FOR EACH BEER DAN LIKE --
SELECT serves.beer AS beer_min, MIN(price) FROM serves, likes WHERE drinker = 'Dan' AND serves.beer = likes.beer GROUP BY beer_min;
-- answer for e--
SELECT bar, beer, price FROM (SELECT serves.beer AS beer_min, MIN(price) FROM serves, likes WHERE drinker = 'Dan' AND serves.beer = likes.beer GROUP BY beer_min) AS beer_min_table, serves WHERE beer_min_table.beer_min = serves.beer AND beer_min_table.min = serves.price; 
--f--
-- ONLY SELECTED OUT the order avg price of all beers --
SELECT * FROM (SELECT beer, AVG(price) FROM serves GROUP BY beer) AS beer_avg ORDER BY beer_avg.avg;
-- ans --
SELECT beer, avg FROM (SELECT * FROM (SELECT beer, AVG(price) FROM serves GROUP BY beer) AS beer_avg ORDER BY beer_avg.avg) AS max_avg_beer WHERE avg = (SELECT MAX(avg) FROM (SELECT * FROM (SELECT beer, AVG(price) FROM serves GROUP BY beer) AS beer_avg ORDER BY beer_avg.avg) AS max_avg_beer WHERE avg < (SELECT MAX(avg) FROM (SELECT * FROM (SELECT beer, AVG(price) FROM serves GROUP BY beer) AS beer_avg ORDER BY beer_avg.avg) AS max_avg_beer_same));
--g--
SELECT DISTINCT frequents.drinker, f_nonlike.bar FROM frequents LEFT OUTER JOIN (SELECT * FROM frequents AS f WHERE NOT EXISTS(SELECT * FROM serves WHERE serves.bar = f.bar AND EXISTS (SELECT * FROM likes WHERE likes.drinker = f.drinker AND likes.beer = serves.beer)) ) AS f_nonlike ON frequents.drinker = f_nonlike.drinker;
--h--
(SELECT DISTINCT likes.drinker FROM serves, likes, frequents WHERE frequents.drinker = likes.drinker AND serves.beer = likes.beer AND frequents.bar = serves.bar) EXCEPT (SELECT DISTINCT drinker FROM ((SELECT drinker, bar FROM frequents) EXCEPT (SELECT DISTINCT likes.drinker, serves.bar FROM serves, likes, frequents WHERE frequents.drinker = likes.drinker AND serves.beer = likes.beer AND frequents.bar = serves.bar)) AS user_go_to_bar_not_like);
--i-- 
(SELECT DISTINCT likes.drinker FROM serves, likes, frequents WHERE frequents.drinker = likes.drinker AND serves.beer = likes.beer AND frequents.bar = serves.bar) EXCEPT (SELECT DISTINCT drinker FROM ((SELECT DISTINCT drinker, bar FROM likes, serves WHERE likes.beer = serves.beer) EXCEPT (SELECT DISTINCT likes.drinker, serves.bar FROM serves, likes, frequents WHERE frequents.drinker = likes.drinker AND serves.beer = likes.beer AND frequents.bar = serves.bar)) AS drinker_fail_go_to_all_bar_theylike);
--j--
--both likes--
SELECT pairs.dkr1, pairs.dkr2, COUNT(*) AS num_both_like FROM (SELECT dr1.name AS dkr1, dr2.name AS dkr2  FROM drinker AS dr1, drinker AS dr2 WHERE dr1.name < dr2.name) AS pairs, likes AS l1, likes AS l2 WHERE l1.drinker = pairs.dkr1 AND l2.drinker = pairs.dkr2 AND l1.beer = l2.beer GROUP BY pairs.dkr1, pairs.dkr2; 
--both frequents--
SELECT pairs.dkr1, pairs.dkr2, COUNT(*) AS num_both_freq FROM (SELECT dr1.name AS dkr1, dr2.name AS dkr2  FROM drinker AS dr1, drinker AS dr2 WHERE dr1.name < dr2.name) AS pairs, frequents AS f1, frequents AS f2 WHERE f1.drinker = pairs.dkr1 AND f2.drinker = pairs.dkr2 AND f1.bar = f2.bar GROUP BY pairs.dkr1, pairs.dkr2; 