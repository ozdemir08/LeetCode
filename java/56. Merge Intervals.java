class Solution {

    private static final int MAX_NUMBER = 10000;

    public int[][] merge(int[][] intervals) {
        ArrayList<Interval> resultIntervals = new ArrayList<Interval>();

        int[] intervalMarkArray = new int[10005];

        // Mark the start and end points.
        for (int i = 0; i < intervals.length; i++) {
            // Assert it has 2 elements as expected.
            int start = intervals[i][0];
            int end = intervals[i][1];
            intervalMarkArray[start]++;
            intervalMarkArray[end]--;
        }

        int currentStart = 0;
        for (int i = 1; i < MAX_NUMBER; i++) {
            intervalMarkArray[i] = intervalMarkArray[i] + intervalMarkArray[i - 1];
            if (intervalMarkArray[i] == 1 && intervalMarkArray[i - 1] == 0) {
                currentStart = i;
            } else if (intervalMarkArray[i] == 0 && intervalMarkArray[i - 1] == 1) {
                resultIntervals.add(new Interval(currentStart, i));
                currentStart = i + 1;
            }
        }

        // Convert interval back to array.
        int[][] resultArray = new int[resultIntervals.size()][2];
        for (int i = 0; i < resultIntervals.size(); i = i + 1) {
            resultArray[i][0] = resultIntervals.get(i).start;
            resultArray[i][1] = resultIntervals.get(i).end;
        }

        return resultArray;
    }

    class Interval {
        int start;
        int end;

        Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}