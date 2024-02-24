SELECT DISTINCT a.album_name
FROM albums a
JOIN album_artist aa ON a.album_id = aa.album_id
JOIN artists ar ON aa.artist_id = ar.artist_id
JOIN artist_genre ag ON ar.artist_id = ag.artist_id
GROUP BY a.album_id
HAVING COUNT(DISTINCT ag.genre_id) > 1;

SELECT DISTINCT t.track_name
FROM tracks t
LEFT JOIN compilation_track ct ON t.track_id = ct.track_id
WHERE ct.compilation_id IS NULL;

SELECT ar.artist_name, t.track_name, t.duration
FROM tracks t
JOIN albums a ON t.album_id = a.album_id
JOIN album_artist aa ON a.album_id = aa.album_id
JOIN artists ar ON aa.artist_id = ar.artist_id
WHERE t.duration = (
    SELECT MIN(duration) FROM tracks
);

SELECT album_name
FROM albums
WHERE album_id IN (
    SELECT album_id
    FROM tracks
    GROUP BY album_id
    HAVING COUNT(track_id) = (
        SELECT MIN(track_count)
        FROM (
            SELECT COUNT(track_id) AS track_count
            FROM tracks
            GROUP BY album_id
        ) AS track_counts
    )
);
