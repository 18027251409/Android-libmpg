package nobleworks.libmpg.test;

import static org.hamcrest.Matchers.hasItemInArray;
import nobleworks.libmpg.MP3Decoder;

import org.apache.commons.lang.ArrayUtils;
import org.hamcrest.Description;
import org.hamcrest.Matcher;
import org.hamcrest.StringDescription;

import android.test.AndroidTestCase;

public class LibmpgTest extends AndroidTestCase
{
    /**
    * Asserts that <code>actual</code> satisfies the condition specified by
    * <code>matcher</code>. If not, an {@link AssertionError} is thrown with
    * information about the matcher and failing value. Example:
    *
    * <pre>
    * assertThat(0, is(1)); // fails:
    * // failure message:
    * // expected: is &lt;1&gt;
    * // got value: &lt;0&gt;
    * assertThat(0, is(not(1))) // passes
    * </pre>
    *
    * @param <T>
    * the static type accepted by the matcher (this can flag obvious
    * compile-time problems such as {@code assertThat(1, is("a"))}
    * @param actual
    * the computed value being compared
    * @param matcher
    * an expression, built of {@link Matcher}s, specifying allowed
    * values
    *
    * @see org.hamcrest.CoreMatchers
    * @see org.junit.matchers.JUnitMatchers
    */
    public static <T> void assertThat(T actual, Matcher<T> matcher)
    {
        assertThat("", actual, matcher);
    }

    /**
    * Asserts that <code>actual</code> satisfies the condition specified by
    * <code>matcher</code>. If not, an {@link AssertionError} is thrown with
    * the reason and information about the matcher and failing value. Example:
    *
    * <pre>
    * :
    * assertThat(&quot;Help! Integers don't work&quot;, 0, is(1)); // fails:
    * // failure message:
    * // Help! Integers don't work
    * // expected: is &lt;1&gt;
    * // got value: &lt;0&gt;
    * assertThat(&quot;Zero is one&quot;, 0, is(not(1))) // passes
    * </pre>
    *
    * @param reason
    * additional information about the error
    * @param <T>
    * the static type accepted by the matcher (this can flag obvious
    * compile-time problems such as {@code assertThat(1, is("a"))}
    * @param actual
    * the computed value being compared
    * @param matcher
    * an expression, built of {@link Matcher}s, specifying allowed
    * values
    *
    * @see org.hamcrest.CoreMatchers
    * @see org.junit.matchers.JUnitMatchers
    */
    public static <T> void assertThat(String reason, T actual, Matcher <T> matcher)
    {
        if (!matcher.matches(actual))
        {
            Description description= new StringDescription();
            description.appendText(reason);
            description.appendText("\nExpected: ");
            matcher.describeTo(description);
            description.appendText("\n got: ");
            description.appendValue(actual);
            description.appendText("\n");
            throw new java.lang.AssertionError(description.toString());
        }
    }

    public void testShouldReportSupportFor8000Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(8000));
    }

    public void testShouldReportSupportFor11025Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(11025));
    }

    public void testShouldReportSupportFor12000Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(12000));
    }

    public void testShouldReportSupportFor16000Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(16000));
    }

    public void testShouldReportSupportFor22500Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(22050));
    }

    public void testShouldReportSupportFor24000Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(24000));
    }

    public void testShouldReportSupportFor32000Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(32000));
    }

    public void testShouldReportSupportFor44100Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(44100));
    }

    public void testShouldReportSupportFor48000Hz()
    {
        int[] supportedRates = MP3Decoder.getSupportedRates();

        assertThat(ArrayUtils.toObject(supportedRates), hasItemInArray(48000));
    }
}
