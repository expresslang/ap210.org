#ifndef DATE_OR_DATE_AND_TIME_H
#define DATE_OR_DATE_AND_TIME_H

// Enumerations
union date_or_date_and_time {
   class date_and_time *ST_date_and_time;
   class date *ST_date;
   };

#endif
