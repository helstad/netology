select g.genre_name, count(distinct ag.artist_id) as artist_count
from artist_genre ag
join genres g on ag.genre_id = g.genre_id
group by g.genre_name;

select count(t.track_id) as track_count
from tracks t
join albums a on t.album_id = a.album_id
where a.release_year between 2000 AND 2020;

select a.album_name , avg(duration) as average_duration 
from tracks t 
join albums a on t.album_id = a.album_id 
group by a.album_name;

select distinct ar.artist_id, ar.artist_name, a.album_name, a.release_year 
from artists ar
left join album_artist aa ON ar.artist_id = aa.artist_id
left join albums a on aa.album_id = a.album_id
where a.album_id is null or a.release_year != 2020;

select c.compilation_name, ar.artist_name 
from compilations c
join compilation_track ct on c.compilation_id = ct.compilation_id
join tracks t on ct.track_id = t.track_id
join albums a on t.album_id = a.album_id
join album_artist aa on a.album_id = aa.album_id
join artists ar on aa.artist_id = ar.artist_id
where ar.artist_name = 'Linkin Park';