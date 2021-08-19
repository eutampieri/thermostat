#include "thermo.h"
#include <stdlib.h>

thermostat_t tst_init(void *dehumidifier_on,
                      void *dehumidifier_off,
                      void *heat_on,
                      void *heat_off,
                      void *ac_on,
                      void *ac_off)
{
    thermostat_t t;
    t.current_humidity = 0.0;
    t.current_temperature = 0.0;
    t.target_humidity = 0.0;
    t.target_temperature = 0.0;
    t.dehumidifier_off = dehumidifier_off;
    t.dehumidifier_on = dehumidifier_on;
    t.heat_off = t.heat_off;
    t.heat_on = t.heat_on;
    t.ac_off = ac_off;
    t.ac_on = ac_on;
    t.enabled = 0;
    t.avg_cooling_rate = 0.0;
    t.avg_heating_rate = 0.0;
    t.avg_ambient_delta_t_rate = 0.0;
    t.avg_humidifying_rate = 0.0;
    t.avg_dehumidifying_rate = 0.0;
    t.status = 0;
    return t;
}

void tst_report_temperature(thermostat_t *th, float t)
{
    th->current_temperature = t;
    tst_evaluate(th);
}
void tst_report_humidity(thermostat_t *t, float rh)
{
    t->current_humidity = rh;
    tst_evaluate(t);
}
void tst_set_temperature(thermostat_t *th, float t)
{
    th->target_temperature = t;
    tst_evaluate(th);
}
void tst_set_humidity(thermostat_t *t, float rh)
{
    t->target_humidity = rh;
    tst_evaluate(t);
}
void tst_enable(thermostat_t *t)
{
    t->enabled = 1;
    tst_evaluate(t);
}
void tst_disable(thermostat_t *t)
{
    t->enabled = 0;
    tst_evaluate(t);
}

uint8_t is_heater(thermostat_t *t)
{
    return t->heat_on != NULL && t->heat_off != NULL;
}
uint8_t is_cooler(thermostat_t *t)
{
    return t->ac_on != NULL && t->ac_off != NULL;
}
uint8_t is_dehumidifier(thermostat_t *t)
{
    return t->dehumidifier_on != NULL && t->dehumidifier_off != NULL;
}
void tst_evaluate(thermostat_t *t)
{
    if (t->enabled)
    {
        if (is_heater(t) && t->avg_ambient_delta_t_rate != 0.0 && t->avg_heating_rate != 0.0)
        {
        }
        if (is_cooler(t) && t->avg_ambient_delta_t_rate != 0.0 && t->avg_cooling_rate != 0.0)
        {
        }
        if (is_dehumidifier(t) && t->avg_humidifying_rate != 0.0 && t->avg_dehumidifying_rate != 0.0)
        {
        }
    }
}
