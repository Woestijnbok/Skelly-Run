#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	m_MaxHealth = 100.0f;
	m_IsDying = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	ResetHealth();
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::ResetHealth()
{
	m_CurrentHealth = m_MaxHealth;
}

int UHealthComponent::GetHealthPercentage() const
{
	return int(float(m_CurrentHealth) / float(m_MaxHealth));
}

bool UHealthComponent::IsDead() const
{
	return m_IsDying;
}

void UHealthComponent::DoDamage(int amount)
{
	if (!m_IsDying)
	{
		m_CurrentHealth = FMath::Clamp((m_CurrentHealth - amount), 0, m_MaxHealth);

		if (m_CurrentHealth == 0)
		{
			m_IsDying = true;
			OnDeath.Broadcast();
		}
		else OnDamage.Broadcast(amount);
	}
}