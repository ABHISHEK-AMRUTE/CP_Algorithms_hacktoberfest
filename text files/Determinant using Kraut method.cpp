static BigInteger det (BigDecimal a [][], int n) {
    try {

    for (int i=0; i<n; i++) {
        boolean nonzero = false;
        for (int j=0; j<n; j++)
            if (a[i][j].compareTo (new BigDecimal (BigInteger.ZERO)) > 0)
                nonzero = true;
        if (!nonzero)
            return BigInteger.ZERO;
    }

    BigDecimal scaling [] = new BigDecimal [n];
    for (int i=0; i<n; i++) {
        BigDecimal big = new BigDecimal (BigInteger.ZERO);
        for (int j=0; j<n; j++)
            if (a[i][j].abs().compareTo (big) > 0)
                big = a[i][j].abs();
        scaling[i] = (new BigDecimal (BigInteger.ONE)) .divide
            (big, 100, BigDecimal.ROUND_HALF_EVEN);
    }

    int sign = 1;

    for (int j=0; j<n; j++) {
        for (int i=0; i<j; i++) {
            BigDecimal sum = a[i][j];
            for (int k=0; k<i; k++)
                sum = sum.subtract (a[i][k].multiply (a[k][j]));
            a[i][j] = sum;
        }

        BigDecimal big = new BigDecimal (BigInteger.ZERO);
        int imax = -1;
        for (int i=j; i<n; i++) {
            BigDecimal sum = a[i][j];
            for (int k=0; k<j; k++)
                sum = sum.subtract (a[i][k].multiply (a[k][j]));
            a[i][j] = sum;
            BigDecimal cur = sum.abs();
            cur = cur.multiply (scaling[i]);
            if (cur.compareTo (big) >= 0) {
                big = cur;
                imax = i;
            }
        }

        if (j != imax) {
            for (int k=0; k<n; k++) {
                BigDecimal t = a[j][k];
                a[j][k] = a[imax][k];
                a[imax][k] = t;
            }

            BigDecimal t = scaling[imax];
            scaling[imax] = scaling[j];
            scaling[j] = t;

            sign = -sign;
        }

        if (j != n-1)
            for (int i=j+1; i<n; i++)
                a[i][j] = a[i][j].divide
                    (a[j][j], 100, BigDecimal.ROUND_HALF_EVEN);

    }

    BigDecimal result = new BigDecimal (1);
    if (sign == -1)
        result = result.negate();
    for (int i=0; i<n; i++)
        result = result.multiply (a[i][i]);

    return result.divide
        (BigDecimal.valueOf(1), 0, BigDecimal.ROUND_HALF_EVEN).toBigInteger();
    }
    catch (Exception e) {
        return BigInteger.ZERO;
    }
}
