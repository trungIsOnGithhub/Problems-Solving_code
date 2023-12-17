class AddBasicColToPlans < ActiveRecord::Migration[7.1]
  def change
    add_column :plans, :name, :string
    add_column :plans, :description, :text
    add_column :plans, :user, :references, null: false, foreign_key: true
  end
end
