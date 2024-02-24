select track_name, duration from tracks order by duration desc limit 1;

select track_name, duration  from tracks t where duration >= '3:30';

select compilation_name  from compilations c where release_year between 2018 and 2020;

select artist_name  from artists a where artist_name not like '% %';

select track_name  from tracks t where track_name  like '%Удар%' or track_name like '%Hit%';