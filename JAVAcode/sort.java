//string sort
String [] strings = new String[5];

Arrays.sort(strings, new Comparator<String>() {
    @Override
    public int compare(String str1, String str2) {
        return (str1+str2).compareTo(str2+str1);
    }
});
