package com.bean;

import android.util.Log;

import com.google.gson.Gson;

import java.io.Serializable;
import java.util.List;

public class Movie implements Serializable {

    /**
     * 返回String
     * @param objStr
     * @return
     */
    public static String callBackString(String objStr) {
        Log.e("tag","==========传入的字符串是=========" + objStr);
        return "gg";
    }

    /**
     * 返回一个Model
     * @param objStr
     * @return
     */
    public static Movie parseModel(String objStr) {
      Log.e("tag","==========objStr is=========" + objStr);
      Movie movie = new Gson().fromJson(objStr, Movie.class);
      return movie;
    }

    /**
     * count : 2
     * start : 0
     * total : 28
     * subjects : [{"rating":{"max":10,"average":8.3,"stars":"45","min":0},"genres":["剧情","喜剧"],"title":"无名之辈","casts":[{"alt":"https://movie.douban.com/celebrity/1274626/","avatars":{"small":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp","large":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp","medium":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp"},"name":"陈建斌","id":"1274626"},{"alt":"https://movie.douban.com/celebrity/1362973/","avatars":{"small":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1478066140.77.webp","large":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1478066140.77.webp","medium":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1478066140.77.webp"},"name":"任素汐","id":"1362973"},{"alt":"https://movie.douban.com/celebrity/1316365/","avatars":{"small":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541855083.14.webp","large":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541855083.14.webp","medium":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541855083.14.webp"},"name":"潘斌龙","id":"1316365"}],"collect_count":190188,"original_title":"无名之辈","subtype":"movie","directors":[{"alt":"https://movie.douban.com/celebrity/1326752/","avatars":{"small":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp","large":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp","medium":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp"},"name":"饶晓志","id":"1326752"}],"year":"2018","images":{"small":"http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp","large":"http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp","medium":"http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp"},"alt":"https://movie.douban.com/subject/27110296/","id":"27110296"},{"rating":{"max":10,"average":7.6,"stars":"40","min":0},"genres":["纪录片"],"title":"生活万岁","casts":[],"collect_count":1775,"original_title":"生活万岁","subtype":"movie","directors":[{"alt":"https://movie.douban.com/celebrity/1334965/","avatars":{"small":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1538708018.57.webp","large":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1538708018.57.webp","medium":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1538708018.57.webp"},"name":"程工","id":"1334965"},{"alt":"https://movie.douban.com/celebrity/1326730/","avatars":{"small":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1542012535.65.webp","large":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1542012535.65.webp","medium":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1542012535.65.webp"},"name":"任长箴","id":"1326730"}],"year":"2018","images":{"small":"http://img7.doubanio.com/view/photo/s_ratio_poster/public/p2539690894.webp","large":"http://img7.doubanio.com/view/photo/s_ratio_poster/public/p2539690894.webp","medium":"http://img7.doubanio.com/view/photo/s_ratio_poster/public/p2539690894.webp"},"alt":"https://movie.douban.com/subject/30337214/","id":"30337214"}]
     * title : 正在上映的电影-北京
     */

    private int count;
    private int start;
    private int total;
    private String title;
    private List<SubjectsBean> subjects;

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public int getStart() {
        return start;
    }

    public void setStart(int start) {
        this.start = start;
    }

    public int getTotal() {
        return total;
    }

    public void setTotal(int total) {
        this.total = total;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public List<SubjectsBean> getSubjects() {
        return subjects;
    }

    public void setSubjects(List<SubjectsBean> subjects) {
        this.subjects = subjects;
    }

    public static class SubjectsBean {
        /**
         * rating : {"max":10,"average":8.3,"stars":"45","min":0}
         * genres : ["剧情","喜剧"]
         * title : 无名之辈
         * casts : [{"alt":"https://movie.douban.com/celebrity/1274626/","avatars":{"small":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp","large":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp","medium":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp"},"name":"陈建斌","id":"1274626"},{"alt":"https://movie.douban.com/celebrity/1362973/","avatars":{"small":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1478066140.77.webp","large":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1478066140.77.webp","medium":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1478066140.77.webp"},"name":"任素汐","id":"1362973"},{"alt":"https://movie.douban.com/celebrity/1316365/","avatars":{"small":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541855083.14.webp","large":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541855083.14.webp","medium":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541855083.14.webp"},"name":"潘斌龙","id":"1316365"}]
         * collect_count : 190188
         * original_title : 无名之辈
         * subtype : movie
         * directors : [{"alt":"https://movie.douban.com/celebrity/1326752/","avatars":{"small":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp","large":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp","medium":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp"},"name":"饶晓志","id":"1326752"}]
         * year : 2018
         * images : {"small":"http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp","large":"http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp","medium":"http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp"}
         * alt : https://movie.douban.com/subject/27110296/
         * id : 27110296
         */

        private RatingBean rating;
        private String title;
        private int collect_count;
        private String original_title;
        private String subtype;
        private String year;
        private ImagesBean images;
        private String alt;
        private String id;
        private List<String> genres;
        private List<CastsBean> casts;
        private List<DirectorsBean> directors;

        public RatingBean getRating() {
            return rating;
        }

        public void setRating(RatingBean rating) {
            this.rating = rating;
        }

        public String getTitle() {
            return title;
        }

        public void setTitle(String title) {
            this.title = title;
        }

        public int getCollect_count() {
            return collect_count;
        }

        public void setCollect_count(int collect_count) {
            this.collect_count = collect_count;
        }

        public String getOriginal_title() {
            return original_title;
        }

        public void setOriginal_title(String original_title) {
            this.original_title = original_title;
        }

        public String getSubtype() {
            return subtype;
        }

        public void setSubtype(String subtype) {
            this.subtype = subtype;
        }

        public String getYear() {
            return year;
        }

        public void setYear(String year) {
            this.year = year;
        }

        public ImagesBean getImages() {
            return images;
        }

        public void setImages(ImagesBean images) {
            this.images = images;
        }

        public String getAlt() {
            return alt;
        }

        public void setAlt(String alt) {
            this.alt = alt;
        }

        public String getId() {
            return id;
        }

        public void setId(String id) {
            this.id = id;
        }

        public List<String> getGenres() {
            return genres;
        }

        public void setGenres(List<String> genres) {
            this.genres = genres;
        }

        public List<CastsBean> getCasts() {
            return casts;
        }

        public void setCasts(List<CastsBean> casts) {
            this.casts = casts;
        }

        public List<DirectorsBean> getDirectors() {
            return directors;
        }

        public void setDirectors(List<DirectorsBean> directors) {
            this.directors = directors;
        }

        public static class RatingBean {
            /**
             * max : 10
             * average : 8.3
             * stars : 45
             * min : 0
             */

            private int max;
            private double average;
            private String stars;
            private int min;

            public int getMax() {
                return max;
            }

            public void setMax(int max) {
                this.max = max;
            }

            public double getAverage() {
                return average;
            }

            public void setAverage(double average) {
                this.average = average;
            }

            public String getStars() {
                return stars;
            }

            public void setStars(String stars) {
                this.stars = stars;
            }

            public int getMin() {
                return min;
            }

            public void setMin(int min) {
                this.min = min;
            }
        }

        public static class ImagesBean {
            /**
             * small : http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp
             * large : http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp
             * medium : http://img3.doubanio.com/view/photo/s_ratio_poster/public/p2539661066.webp
             */

            private String small;
            private String large;
            private String medium;

            public String getSmall() {
                return small;
            }

            public void setSmall(String small) {
                this.small = small;
            }

            public String getLarge() {
                return large;
            }

            public void setLarge(String large) {
                this.large = large;
            }

            public String getMedium() {
                return medium;
            }

            public void setMedium(String medium) {
                this.medium = medium;
            }
        }

        public static class CastsBean {
            /**
             * alt : https://movie.douban.com/celebrity/1274626/
             * avatars : {"small":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp","large":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp","medium":"http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp"}
             * name : 陈建斌
             * id : 1274626
             */

            private String alt;
            private AvatarsBean avatars;
            private String name;
            private String id;

            public String getAlt() {
                return alt;
            }

            public void setAlt(String alt) {
                this.alt = alt;
            }

            public AvatarsBean getAvatars() {
                return avatars;
            }

            public void setAvatars(AvatarsBean avatars) {
                this.avatars = avatars;
            }

            public String getName() {
                return name;
            }

            public void setName(String name) {
                this.name = name;
            }

            public String getId() {
                return id;
            }

            public void setId(String id) {
                this.id = id;
            }

            public static class AvatarsBean {
                /**
                 * small : http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp
                 * large : http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp
                 * medium : http://img7.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1415455964.31.webp
                 */

                private String small;
                private String large;
                private String medium;

                public String getSmall() {
                    return small;
                }

                public void setSmall(String small) {
                    this.small = small;
                }

                public String getLarge() {
                    return large;
                }

                public void setLarge(String large) {
                    this.large = large;
                }

                public String getMedium() {
                    return medium;
                }

                public void setMedium(String medium) {
                    this.medium = medium;
                }
            }
        }

        public static class DirectorsBean {
            /**
             * alt : https://movie.douban.com/celebrity/1326752/
             * avatars : {"small":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp","large":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp","medium":"http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp"}
             * name : 饶晓志
             * id : 1326752
             */
            private String alt;
            private AvatarsBeanX avatars;
            private String name;
            private String id;

            public String getAlt() {
                return alt;
            }

            public void setAlt(String alt) {
                this.alt = alt;
            }

            public AvatarsBeanX getAvatars() {
                return avatars;
            }

            public void setAvatars(AvatarsBeanX avatars) {
                this.avatars = avatars;
            }

            public String getName() {
                return name;
            }

            public void setName(String name) {
                this.name = name;
            }

            public String getId() {
                return id;
            }

            public void setId(String id) {
                this.id = id;
            }

            public static class AvatarsBeanX {
                /**
                 * small : http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp
                 * large : http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp
                 * medium : http://img3.doubanio.com/view/celebrity/s_ratio_celebrity/public/p1541992522.36.webp
                 */
                private String small;
                private String large;
                private String medium;

                public String getSmall() {
                    return small;
                }

                public void setSmall(String small) {
                    this.small = small;
                }

                public String getLarge() {
                    return large;
                }

                public void setLarge(String large) {
                    this.large = large;
                }

                public String getMedium() {
                    return medium;
                }

                public void setMedium(String medium) {
                    this.medium = medium;
                }
            }
        }
    }
}
