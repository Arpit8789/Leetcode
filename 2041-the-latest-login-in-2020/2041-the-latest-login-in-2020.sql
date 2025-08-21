SELECT l.user_id, l.time_stamp AS last_stamp
FROM Logins l
WHERE l.time_stamp = (
    SELECT MAX(l2.time_stamp)
    FROM Logins l2
    WHERE l2.user_id = l.user_id
      AND YEAR(l2.time_stamp) = 2020
)
